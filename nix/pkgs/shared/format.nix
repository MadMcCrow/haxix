# format.nix
# a haxe library for interacting with file formats
{ pkgs, inputs }:
let
  # generic builder
  generic = { version, src }:
    pkgs.haxePackages.format.overrideAttrs
    (finalAttrs: previousAttrs: { inherit version src; });
  # implementation
in generic {
  version = "3.6.0";
  src = inputs.haxe_format;
}
