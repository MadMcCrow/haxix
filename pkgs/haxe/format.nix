# format.nix
# a haxe library for interacting with file formats
{ pkgs, inputs, ... }:
let
  # pinned sources
  sources = import ../_npins;
in
pkgs.haxePackages.format.overrideAttrs {
    version = "3.8.0"; # this is the latest known release
    src = sources."haxe-format";
  }
