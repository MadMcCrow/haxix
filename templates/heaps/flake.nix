# this flakes uses Haxix
{
  description = "A Flake with Haxix";
  inputs = {
    # your friendly local nixpkgs
    nixpkgs = {
      type = "indirect";
      id = "nixpkgs";
    };
    # haxix contains all you need for Haxe development
    haxix.url = "github:MadMcCrow/haxix";
  };
  outputs =
    {
      self,
      haxix,
      nixpkgs,
      ...
    }:
    let
      # supported systems
      systems = [
        "x86_64-linux"
        "aarch64-darwin"
        "x86_64-darwin"
      ];

      # default system-agnostic flake implementation :
      flake = system: {
        # implement your flake here ;)
        packages."${system}" = rec {
          my-project = haxix.legacyPackages."${system}".heaps.buildHeapsGame {
            src = self;
            name = "my-project";
            version = "0.0.1-alpha";
          };
          default = my-project;
        };
      };

    in
    # gen for all systems :
    builtins.foldl' (x: y: nixpkgs.lib.recursiveUpdate x y) { } (map flake systems);
}
