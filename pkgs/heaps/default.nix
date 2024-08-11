# heaps/default.nix
# heaps.io is a "game engine" written in haxe
{ callPackage, inputs, ... }@args:
let
  heaps = callPackage ./generic.nix (
    args
    // {
      src = inputs.heaps;
      version = "2.0.0";
    }
  );
  lib = callPackage ./lib.nix (args // { inherit heaps; });

in
{
  heaps = heaps // lib;
}
