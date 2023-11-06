# hashlink.nix
# Hashlink interpreter for haxe
# TODO : split hashlink and it's libraries
# for this we need to use different outputs in generic
{ pkgs, hashlink, haxelib }:
let

  hllibs = ["openal" "sdl" ]; 

  # Custom HL with libraries for haxelib added
  generic = { version, src }: let
    hl = pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      buildInputs = previousAttrs.buildInputs ++ [pkgs.libpng];
      postInstall = (previousAttrs.postInstall or "") + ''
        ${haxelib.installHaxeLib {
          libname = "${finalAttrs.pname}";
          files = "other/haxelib/*";
          inherit version;
        }}
      '';
    });
    libraries = builtins.listToAttrs (builtins.map (x: pkgs.lib.attrsets.nameValuePair "hl${x}" (haxelib.mkHaxelib {
    inherit version;
    libname = "hl${x}";
    src = "${src}/libs/${x}";
    meta = hl.meta;
  })) hllibs );
    in {
      inherit hl;
      pkgs = [hl] ++ builtins.attrValues libraries;
    } // libraries;


in {

  # HASHLINK : flake latest version
  hashlink_latest =  generic {
    version = "latest";
    src = hashlink;
  };
}
