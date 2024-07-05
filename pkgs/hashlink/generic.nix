# hashlink.nix
# Hashlink interpreter for haxe
{ version, src, lib, buildEnv, hashlink, haxe, libpng, ... }:
let
  hl = hashlink.overrideAttrs (finalAttrs: previousAttrs: {
    inherit version src;
    buildInputs = previousAttrs.buildInputs ++ [ libpng ];
    postInstall = (previousAttrs.postInstall or "") + ''
      ${haxe.installHaxelib {
        pname = "${finalAttrs.pname}";
        files = "other/haxelib/*";
        inherit version;
      }}
    '';
  });
  # hlsdl, etc ...
  hl-lib = name: description:
    haxe.buildHaxelib {
      inherit version;
      libname = "hl${name}";
      src = "${src}/libs/${name}";
      meta = hl.meta // { inherit description; };
    };
in buildEnv {
  name = "hashlink";
  paths = [
    hl
    (hl-lib "sdl" "sdl2 support for hl")
    (hl-lib "openal" "hl openal library")
  ];
}
