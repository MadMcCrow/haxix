# heaps/default.nix
# heaps.io is a "game engine" written in haxe
{ callPackage, inputs, ... }:
let 
 heaps = callPackage ./generic.nix {
    src = inputs.heaps;
    version = "2.0.0";
  };
in {
  heaps = heaps // (callPackage ./lib.nix {});
}
