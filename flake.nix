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
    # heaps : the game engine
    heaps = {
      url = "github:HeapsIO/heaps";
      flake = false;
    };
    # raylib source code
    raylib = {
      url = "github:Raysan5/raylib?ref=refs/tags/5.0";
      flake = false;
    };
    # raylib haxe bindings
    raylib-hx = {
      url = "github:foreignsasquatch/raylib-hx";
      flake = false;
    };
  };

  outputs =
    { self, nixpkgs, ... }@inputs:
    let
      # multiplatform support
      systems = [
        "x86_64-linux"
        # "aarch64-linux" <- not supported yet
        "aarch64-darwin"
        "x86_64-darwin"
      ];
      # the actual flake for every system
      flake =
        system:
        let
          pkgs = import nixpkgs { inherit system; };
          packages = pkgs.callPackage ./pkgs { inherit inputs; };
          # demos = pkgs.callPackage ./demo ({ inherit inputs; } // packages);
        in
        {
          legacyPackages."${system}" = packages;
          devShells."${system}" = pkgs.callPackages ./pkgs/shell.nix packages;
          checks."${system}" = pkgs.callPackages ./pkgs/checks.nix packages;
        };
    in
    {
      # template for heaps projects :
      templates = rec {
        default = heaps; # we might not wanna be that opiniated
        heaps = {
          path = ./templates/heaps;
          description = "A simple haxe game with heaps";
          welcomeText = "";
        };
        lime = {
          path = ./templates/lime;
          description = "A simple haxe project with lime";
          welcomeText = "";
        };
      };
    }
    # gen for all systems :
    // (builtins.foldl' (x: y: nixpkgs.lib.recursiveUpdate x y) { } (map flake systems));

}
