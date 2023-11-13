{pkgs, haxe_latest, hxcpp } :
let 

  withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];
  
  # generic variant of hxcpp
  generic = {src, version} : pkgs.stdenv.mkDerivation {
      inherit src version;
      pname= "hxcpp";

      buildInputs =  [ haxe_latest pkgs.neko ];

      postFixup = ''
      REPO=$(pwd)
      cd $REPO/tools/run
      haxe compile.hxml
      cd $REPO/tools/hxcpp
      haxe compile.hxml
      cd $REPO

      for f in $out/lib/haxe/hxcpp/${withCommas version}/{,project/libs/nekoapi/}bin/Linux{,64}/*; do
        chmod +w "$f"
        patchelf --set-interpreter $(cat $NIX_CC/nix-support/dynamic-linker)   "$f" || true
        patchelf --set-rpath ${ pkgs.lib.makeLibraryPath [ pkgs.stdenv.cc.cc ] }  "$f" || true
      done
    '';
      
      installPhase = ''
        mkdir -p "$out/lib/haxe/hxcpp/${withCommas version}"
        echo -n "${version}" > $out/lib/haxe/hxcpp/.current
        cp -dpR ./src "$out/lib/haxe/hxcpp/${withCommas version}/"
        cp *.n $out/lib
      '';

      meta = {
        homepage = "https://github.com/HaxeFoundation/hxcpp";
        license = pkgs.haxe.meta.license;
        platforms = pkgs.lib.platforms.all;
        description = throw "please write meta.description";
      };
    };
in
{
  hxcpp_latest = generic {
      src = hxcpp;
      version = "4.3.15";
    };
}