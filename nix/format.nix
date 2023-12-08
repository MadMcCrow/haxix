# format.nix
# a haxe library for interacting with file formats
{
  pkgs,
  haxe_format,
}: let
  generic = {
    version,
    src,
  }:
    pkgs.haxePackages.format.overrideAttrs
    (finalAttrs: previousAttrs: {inherit version src;});
in {
  # FORMAT : alpha fixed version
  format_latest = generic {
    src = haxe_format;
    version = "latest";
  };
}
