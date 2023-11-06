# darwin/hashlink.nix
# Hashlink interpreter for haxe, on MacOS.
# only intel Mac supported, uses rosetta to run on M1
{ pkgs, hashlink, haxelib } :
let
  # haxe libs from hl
  hllibs = [ "openal" "sdl" "fmt" ];

  # we need objective-C
  objc = with pkgs.darwin; [ apple_sdk_11_0.objc4 libobjc ];

  # we support platform
  meta = pkgs.hashlink.meta // {
    platforms = pkgs.lib.platforms.darwin;
  };

  # make Flags to detect objective C
  ObjCmakeFlags = let
    concatObjc = dir : builtins.concatStringsSep "," (map (x: "${x}/${dir}") objc);
  in [
   "CPATH=${concatObjc "include"}"
   "LIBRARY_PATH=${concatObjc "lib"}"
  ];

  # Custom HL with libraries for haxelib added
  generic = { version, src }:
    let
      hl = pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
        inherit version src meta;
      buildInputs = previousAttrs.buildInputs ++ [ pkgs.libpng ]++ objc;
      makeFlags = previousAttrs.makeFlags ++ ObjCmakeFlags;
        postInstall = (previousAttrs.postInstall or "") + ''
          ${haxelib.installHaxeLib {
            libname = "${finalAttrs.pname}";
            files = "other/haxelib/*";
            inherit version;
          }}
        '';
      });
      libraries = builtins.listToAttrs (builtins.map (x:
        pkgs.lib.attrsets.nameValuePair "hl${x}" (haxelib.mkHaxelib {
          inherit version meta;
          libname = "hl${x}";
          src = "${src}/libs/${x}";
        })) hllibs);
    in {
      inherit hl;
      pkgs = [ hl ] ++ builtins.attrValues libraries;
    } // libraries;
  

in {
  # HASHLINK : flake latest version
  hashlink_latest = generic {
    src = hashlink;
    version = "latest";
  };
}
