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
    # Dox : the documentation tool
    dox = {
      url = "github:HaxeFoundation/dox";
      flake = false;
    };
    # format : the format support library
    haxe_format = {
      url = "github:HaxeFoundation/format";
      flake = false;
    };
    # hxcpp : runtime support for the C++ backend 
    # of the Haxe compiler.
    hxcpp = {
      url = "github:HaxeFoundation/hxcpp?ref=refs/tags/v4.3.15";
      flake = false;
    };
    # heaps : the game engine
    heaps = {
      url = "github:HeapsIO/heaps";
      flake = false;
    };
    # formatter
    formatter = {
      url = "github:HaxeCheckstyle/haxe-formatter";
      flake = false;
    };
    # raylib
    raylib = {
      url = "github:raysan5/raylib?ref=refs/tags/4.5.0";
      flake = false;
    };
    # raylib haxe bindings
    raylib-hx = {
      url = "github:foreignsasquatch/raylib-hx";
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
      forAllSystems = f: inputs.nixpkgs.lib.genAttrs systems f;

      # import functions:
      haxix = system: (import ./nix { inherit inputs system; });

      # an example of a game
      heaps-demo = system:
        (haxix system).heaps.mkGame {
          name = "heaps-helloworld";
          src = ./demo/heaps;
          version = "0.0.1-alpha";
          native = false;
        };

        raylib-demo = system:
        (haxix system).raylib.mkGame {
          name = "heaps-helloworld";
          src = ./demo/heaps;
          version = "0.0.1-alpha";
          native = false;
        };
    in {
      # template for heaps projects :
      templates.default = {
        path = ./template;
        description = "A simple haxe/heaps game project";
        welcomeText = "";
      };

      # expose functions :
      lib = forAllSystems (system: {
        mkHaxelib = (haxix system).haxelib.mkHaxelib;
        mkHaxedoc = (haxix system).dox.mkHaxedoc;
        mkHeapsGame = (haxix system).heaps.mkGame;
        mkHeapsShell = (haxix system).heaps.mkShell;
      });

      # All important packages and the demo
      packages = forAllSystems (system: {
        # haxelang :
        haxe = (haxix system).haxe.haxe_latest;
        hashlink = (haxix system).hashlink.hashlink_latest;
        # libs :
        format = (haxix system).format.format_latest;
        dox = (haxix system).dox.dox_latest;
        # helloworld :
        demo = heaps-demo system;
      });

      # checks
      # TODO : improve to only build minimal checks
      checks = forAllSystems (system: { demo = heaps-demo system; });

      # shell for making haxe stuff
      devShells = forAllSystems (system: { default = (haxix system).shell; });
    };
}
