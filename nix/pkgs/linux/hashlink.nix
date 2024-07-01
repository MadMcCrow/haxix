# hashlink.nix
# Hashlink interpreter for haxe
{ pkgs, inputs, haxelib } :
let
  inherit (pkgs) lib;
  # Custom HL with libraries for haxelib added
  generic = { version, src }:
    let
      hl = pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
        inherit version src;
        buildInputs = previousAttrs.buildInputs ++ [ pkgs.libpng ];
        postInstall = (previousAttrs.postInstall or "") + ''
          ${haxelib.installHaxeLib {
            libname = "${finalAttrs.pname}";
            files = "other/haxelib/*";
            inherit version;
          }}
        '';
      });
      # hlsdl, etc ...
      hl-lib = name: description:
        haxelib.mkHaxelib {
          inherit version;
          libname = "hl${name}";
          src = "${src}/libs/${name}";
          meta = hl.meta // { inherit description; };
        };
    in pkgs.buildEnv {
      name = "hashlink";
      paths = [
        hl
        (hl-lib "sdl" "sdl2 support for hl")
        (hl-lib "openal" "hl openal library")
      ];
    };
  # implementation
in generic {
  version = "1.14.0";
  src = inputs.hashlink;
}
