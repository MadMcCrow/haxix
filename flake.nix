{
  description = "Build a haxe project";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    };

  outputs = { self, nixpkgs, crane, fenix, ... }:
      let
        system = "x86_64-linux";

        pkgs = import nixpkgs {
          inherit system;
        };

        inherit (pkgs) lib;

        enginePackages = with pkgs; [haxe haxePackages.heaps haxePackages.hlopenal haxePackages.hlsdl hashlink] ;

        my-game = pkgs.stdenv.mkDerivation {
          name = "my-game";
          nativeBuildInputs = enginePackages;
          buildInputs = enginePackages;
        };

      in
      {

        packages = {
          default = my-game;
        };

        devShells.default = mkShell {
          packages = enginePackages;
        };
      }
}
