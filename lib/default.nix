# flake part module for lib
{
  inputs,
  self,
  ...
}:
let
  # expose our packages :
  haxe_pkgs = system: self.packages.${system};
  libs = [
    ./haxedoc.nix
    ./haxelib.nix
    ./heapslib.nix
    ./limelib.nix
    ./raylib.nix
  ];
in
{
  # not implemented
}
