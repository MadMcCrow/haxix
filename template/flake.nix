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
  outputs = {
    self,
    haxix,
    nixpkgs,
    ...
  } @ inputs: let
    # supported systems
    systems = ["x86_64-linux" "aarch64-darwin" "x86_64-darwin"];

    # default system-agnostic flake implementation :
    flake = system: let
      haxix-lib = haxix.lib."${system}";
      # heaps game example :
      my-project = haxix-lib.mkHeapsGame {
        src = self;
        name = "my-project";
        version = "0.0.1-alpha";
      };
    in {
      # implement your flake here ;)
      packages."${system}" = {
        inherit my-project;
        default = my-project;
      };
    };
    # gen for all systems :
  in
    builtins.foldl' (x: y: nixpkgs.lib.recursiveUpdate x y) {} (map flake systems);
}
