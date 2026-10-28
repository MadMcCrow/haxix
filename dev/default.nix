# flake part module for dev
{
  inputs,
  self,
  ...
}:
let
    treefmt = import ./treefmt.nix;
in
{
  imports = [ inputs.treefmt-nix.flakeModule ];

  flake = { inherit treefmt; };

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
      # add packages to checks
      checks = pkgs.callPackages ./checks.nix haxe_pkgs;
      #
      devShells = pkgs.callPackages ./shells.nix haxe_pkgs;
      # add treefmt formatter
      packages.treefmt = inputs.treefmt-nix.lib.mkWrapper pkgs treefmt;
    };
}
