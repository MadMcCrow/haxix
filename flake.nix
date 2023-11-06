{
  description = "flake to help build a haxe project";

  inputs = {
    # latest nixpkgs
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

    # MacOS support
    nixpkgs-darwin.url = "github:NixOS/nixpkgs/nixpkgs-23.05-darwin";

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

  outputs = { self, ... }@inputs:
    let
      # multiplatform support
      # only tested on x86_64 linux
      systems = [
        "x86_64-linux"
        # "aarch64-linux" <- not supported yet
        "aarch64-darwin"
        "x86_64-darwin"
      ];

      haxix = system: (import ./nix { inherit inputs system; });

      forAllSystems = f: inputs.nixpkgs.lib.genAttrs systems f;

      # the game itself
      demo = system:
        (haxix system).heaps.mkGame {
          name = "helloworld";
          src = ./demo;
          version = "0.0.1-alpha";
          debug = false;
          release = false;
        };

    in {

      # template for godot projects :
      templates = {
        default = {
          path = ./template;
          description = "A simple haxe game project";
          welcomeText = "";
        };
      };

      # expose functions :
      lib = forAllSystems (system: {
        mkHaxelib = (haxix system).haxelib.mkHaxelib;
        mkHeapsGame = (haxix system).heaps.mkGame;
        mkHeapsShell = (haxix system).heaps.mkShell;
      });

      # add our demo
      packages = forAllSystems (system: rec {
        haxe = (haxix system).haxe.haxe_latest;
        hashlink = (haxix system).hashlink.hashlink_latest;
        default = demo system;
      });

      # shell for the demo
      devShells = forAllSystems
        (system: { default = (haxix system).heaps.mkShell (demo system); });
    };
}
