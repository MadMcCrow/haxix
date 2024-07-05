# hxcpp/generic
# how to build hxcpp from sources
{ pkgs, haxe, version, src, ... }:
let
  withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];
  # TODO : use buildHaxelib
in pkgs.stdenv.mkDerivation {
  pname = "hxcpp";
  buildInputs = [ haxe pkgs.neko ];
  inherit src version;
  buildPhase = ''
    REPO=$(pwd)
    cd $REPO/tools/run
    haxe compile.hxml
    cd $REPO/tools/hxcpp
    haxe compile.hxml
    # haxe compile-cpp.hxml
    cd $REPO
  '';

  installPhase = ''
    runHook preInstall
    (
      if [ $(ls $src | wc -l) == 1 ]; then
        cd $src/* || cd $src
      else
        cd $src
      fi
      mkdir -p "$out/lib/haxe/hxcpp/${withCommas version}"
      echo -n "${version}" > $out/lib/haxe/hxcpp/.current
      cp -dpR * "$out/lib/haxe/hxcpp/${withCommas version}/"
    )
    runHook postInstall
  '';
  postFixup = ''
    for f in $out/lib/haxe/hxcpp/${
      withCommas version
    }/{,project/libs/nekoapi/}bin/Linux{,64}/*; do
      chmod +w "$f"
      patchelf --set-interpreter $(cat $NIX_CC/nix-support/dynamic-linker)   "$f" || true
      patchelf --set-rpath ${
        pkgs.lib.makeLibraryPath [ pkgs.stdenv.cc.cc ]
      }  "$f" || true
    done
  '';
  inherit (pkgs.haxePackages.hxcpp) meta;
}
