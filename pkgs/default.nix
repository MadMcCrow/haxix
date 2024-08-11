# default.nix
{
  lib,
  callPackage,
  inputs,
  ...
}:
builtins.foldl' (x: y: lib.recursiveUpdate x (y (x // { inherit inputs; }))) { } (
  map (x: (args: callPackage x args)) [
    ./haxe
    ./hxcpp
    ./format
    ./hashlink
    ./heaps
    ./dox
    ./haxefmt
    ./raylib
    ./hxp
    ./lime
  ]
)
