# format.nix
# a haxe library for interacting with file formats
{ pkgs, inputs, ... }: {
  format = pkgs.haxePackages.format.overrideAttrs (finalAttrs: previousAttrs: {
    version = "3.8.0";
    src = inputs.haxe_format;
  });
}
