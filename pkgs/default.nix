# default.nix
{
  lib,
  callPackage,
  inputs,
  ...
}:
let
  # call package with previously defined packages
  appendPackages = pkgs: module: pkgs // callPackage module (pkgs // { inherit inputs; });
in
builtins.foldl' appendPackages { } [
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
