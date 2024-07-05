# hxcpp/default.nix
# hxcpp is the cpp exporter for haxe 
{ callPackage, inputs, ... }:
let
  raylib = callPackage ./raylib.nix { inherit inputs; };
  raylib-hx = callPackage ./raylib-hx.nix { inherit inputs raylib; };
  lib = callPackage ./lib.nix { inherit inputs raylib raylib-hx; };
in {
  inherit raylib;
  raylib-hx = raylib-hx // lib;
}
