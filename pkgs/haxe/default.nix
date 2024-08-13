# haxe/default.nix
# provide latest haxe and haxelib builer
{ callPackage, ... }:
let
  haxe = callPackage ./generic.nix {
    version = "4.3.6"; # using something else than a number may break packages
  };
  lib = callPackage ./lib.nix { inherit haxe; };
in
{
  haxe = haxe // lib;
}
