{
  description = "flake to help build a haxe project";

  inputs = {
    # we only use nixpkgs for now, we should move to getting haxe and heaps with inputs instead
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = {
    self,
    nixpkgs,
    ...
  } @ inputs:
    with builtins; let
      # multiplatform support
      # only tested on x86_64 linux
      systems = ["x86_64-linux" "aarch64-linux" "aarch64-darwin"];
      forAllSystems = function:
        nixpkgs.lib.genAttrs systems
        (system: function (import nixpkgs {inherit system;}));

      mkAllSystems = set: forAllSystems (pkgs: mapAttrs (name: value: value pkgs) set);

      # sub modules
      heaps = import nix/heaps.nix;
      haxe = import nix/haxe.nix;

      # the game itself
      helloworld = pkgs:
        (heaps pkgs).buildGame {
          name = "helloworld";
          src = self;
          version = "0.0.1-alpha";
          debug = false;
          release = false;
        };

      heapsShell = pkgs: (heaps pkgs).mkShell (helloworld pkgs);
    in {
      # expose our heaps and haxe functions
      lib = mkAllSystems {inherit heaps haxe;};

      # add our demo
      packages =
        mkAllSystems rec
        {
          inherit helloworld;
          default = helloworld;
        };

      # shell for the demo
      devShells = mkAllSystems {default = heapsShell;};
    };
}
