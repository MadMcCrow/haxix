{
  description = "flake to help build a haxe project";

  inputs = {
    # latest nixpkgs
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    # haxe : the language
    haxe = {
      type = "git";
      url = "https://github.com/HaxeFoundation/haxe.git";
      ref = "development";
      flake = false;
      submodules = true;
    };
    # hashlink : the haxe interpreter
    hashlink = {
      url = "github:HaxeFoundation/hashlink?ref=refs/tags/latest";
      flake = false;
    };
    # format : the format support library
    haxe_format = {
      url = "github:HaxeFoundation/format";
      flake = false;
    };
    # heaps : the game engine
    heaps = {
      url = "github:HeapsIO/heaps";
      flake = false;
    };
  };

  outputs = { self, nixpkgs, ... }@inputs:
    let
      # multiplatform support
      # only tested on x86_64 linux
      systems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" ];
      forAllSystems = function:
        nixpkgs.lib.genAttrs systems
        (system: function (import nixpkgs { inherit system; }));

      mkAllSystems = set:
        forAllSystems (pkgs: builtins.mapAttrs (name: value: value pkgs) set);

      # sub modules
      haxe = pkgs: (import nix/haxe.nix { inherit inputs pkgs; });
      heaps = pkgs: (import nix/heaps.nix { inherit inputs pkgs; });

      # the game itself
      demo = pkgs:
        (heaps pkgs).buildGame {
          name = "helloworld";
          src = ./demo;
          version = "0.0.1-alpha";
          debug = false;
          release = false;
        };

    in {
      # expose our heaps and haxe functions
      lib = mkAllSystems { inherit heaps haxe; };

      # add our demo
      packages = mkAllSystems rec {
        inherit demo;
        default = demo;
      };

      # shell for the demo
      devShells = mkAllSystems { default = pkgs: (heaps pkgs).mkShell (demo pkgs); };
    };
}
