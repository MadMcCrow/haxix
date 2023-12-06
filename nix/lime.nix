# lime.nix
{
  pkgs,
  lime,
  haxelib,
  haxe_latest,
}: let
  inherit (pkgs) lib;

  generic = {
    version,
    src,
  }:
    haxelib.mkHaxelib {
      inherit version;
      libname = "lime";
    };
in {
  lime_latest = generic {
    version = "latest";
    src = lime;
  };
}
