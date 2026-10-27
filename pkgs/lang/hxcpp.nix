# hxcpp.nix
# hxcpp is the cpp exporter for haxe
# how to build hxcpp from sources
{
  lib,
  stdenv,
  neko,
  haxePackages,
  haxe,
  ...
}:
let
  # pinned sources
  pname = "hxcpp";
  pin = (import ../_npins).${pname};
  inherit (pin) version;
  withCommas = lib.replaceStrings [ "." ] [ "," ];

  # we need to figure out how to make cppia work !
  # cppia = "REPO=$(pwd)
  #   cd $REPO/project
  #   haxe compile-cppia.hxml
  #   cd $REPO
  #   ";
in
stdenv.mkDerivation {
  src = pin;
  inherit pname version;
  buildInputs = [
    haxe
    neko
  ];
  buildPhase = ''
    REPO=$(pwd)
    cd $REPO/tools/run
    ${lib.getExe haxe} compile.hxml
    cd $REPO/tools/hxcpp
    ${lib.getExe haxe} compile.hxml
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
    for f in $out/lib/haxe/hxcpp/${withCommas version}/{,project/libs/nekoapi/}bin/Linux{,64}/*; do
      chmod +w "$f"
      patchelf --set-interpreter $(cat $NIX_CC/nix-support/dynamic-linker)   "$f" || true
      patchelf --set-rpath ${lib.makeLibraryPath [ stdenv.cc.cc ]}  "$f" || true
    done
  '';

  inherit (haxePackages.hxcpp) meta;
}
