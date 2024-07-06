# hxcpp/default.nix
# hxcpp is the cpp exporter for haxe 
{ callPackage, inputs, haxe, ... }:
let
  raylib = callPackage ./raylib.nix {
    inherit inputs;
    version = "5.0";
  };
  raylib-hx = callPackage ./raylib-hx.nix {
    inherit inputs raylib haxe;
    version = "5.0.0";
  };
  lib = callPackage ./lib.nix { inherit inputs raylib raylib-hx haxe; };
in {
  inherit raylib;
  raylib-hx = raylib-hx // lib;
}
