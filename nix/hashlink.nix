# hashlink.nix
# Hashlink interpreter for haxe
# TODO : split hashlink and it's libraries
# for this we need to use different outputs in generic
{
  pkgs,
  hashlink,
  haxelib,
}: let
  inherit (pkgs) lib;

  # darwin support
  darwinOverrides =
    if pkgs.stdenv.isDarwin
    then (import ./darwin/hashlink.nix pkgs)
    else (f: p: {});

  # Custom HL with libraries for haxelib added
  generic = {
    version,
    src,
  }: let
    hl =
      (pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
        inherit version src;
        buildInputs = previousAttrs.buildInputs ++ [pkgs.libpng];
        postInstall =
          (previousAttrs.postInstall or "")
          + ''
            ${haxelib.installHaxeLib {
              libname = "${finalAttrs.pname}";
              files = "other/haxelib/*";
              inherit version;
            }}
          '';
      }))
      .overrideAttrs
      darwinOverrides;
    # hlsdl, etc ...
    hl-lib = name: description:
      haxelib.mkHaxelib {
        inherit version;
        libname = "hl${name}";
        src = "${src}/libs/${name}";
        meta = hl.meta // {inherit description;};
      };
  in
    pkgs.buildEnv {
      name = "hashlink";
      paths = [
        hl
        (hl-lib "sdl" "sdl2 support for hl")
        (hl-lib "openal" "hl openal library")
      ];
    };
in {
  # HASHLINK : flake latest version
  hashlink_latest = generic {
    version = "latest";
    src = hashlink;
  };
}
