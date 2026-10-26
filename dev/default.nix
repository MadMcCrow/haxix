# flake part module for dev
{
  inputs,
  self,
  ...
}:
{
  imports = [ inputs.treefmt-nix.flakeModule ];

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
      checks = pkgs.callPackages ./checks.nix haxe_pkgs;
      devShells = pkgs.callPackages ./shells.nix haxe_pkgs;
      treefmt = import ./treefmt;
      # add formatter package
      packages.formatter = inputs.treefmt-nix.lib.mkWrapper pkgs (import ./treefmt);
    };
}
