{
  description = "flake to help build a haxe project";

  inputs = {
    # latest nixpkgs
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

    # darwin support
    # see https://nixos.org/manual/nixpkgs/unstable/release-notes#x86_64-darwin-26.11
    nixpkgs-darwin.url = "github:NixOS/nixpkgs/nixpkgs-26.05-darwin";

    # flake support
    flake-parts = {
      url = "github:hercules-ci/flake-parts";
      inputs.nixpkgs-lib.follows = "nixpkgs";
    };

    # allows working without flakes
    # flake = false is optional
    flake-compat = {
      url = "https://git.lix.systems/lix-project/flake-compat/archive/main.tar.gz";
      flake = false;
    };

    # import all implicitly
    import-tree.url = "github:denful/import-tree";

    # auto format repo
    treefmt-nix = {
      url = "github:numtide/treefmt-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };
      outputs =
        inputs@{
          flake-parts,
          nixpkgs,
          self,
          ...
        }:
        flake-parts.lib.mkFlake { inherit inputs; } (
          { lib, ... }: {

            # multiplatform support
            systems = [
              "x86_64-linux"
              # "aarch64-linux" <- not supported yet
              "aarch64-darwin"
              # "x86_64-darwin" -> not supported anymore
            ];

            # TODO : replace by auto-detect directories
            imports = [
              #./demo # runnable demos
              #./dev # shells and development tools
              #./docs
              #./lib
              ./pkgs
              #./templates
            ];
          }
        );

}
