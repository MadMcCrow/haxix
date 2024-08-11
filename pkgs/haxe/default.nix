# haxe/default.nix
# provide latest haxe and haxelib builer
{ callPackage, ... }:
let
  haxe = callPackage ./generic.nix {
    version = "4.3.4"; # using something else than a number may break packages
  };
in
{
  haxe = haxe // (callPackage ./lib.nix { inherit haxe; });
}
