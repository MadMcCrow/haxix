# flake part module for lib
{
  inputs,
  self,
  ...
}:
{

  perSystem =
    {
      pkgs,
      lib,
      system,
      ...
    }:
    let
      # expose our packages :
      haxe_pkgs = self.packages.${system};
      in
      {
      lib = lib.fold (a: b: a // b) {} (
          map (x: import x haxe_pkgs)
          [
            ./haxedoc.nix
            ./haxelib.nix
            ./heapslib.nix
            ./limelib.nix
            ./raylib.nix
          ]);
      };
}
