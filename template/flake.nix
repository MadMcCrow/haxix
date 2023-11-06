# this flakes uses Haxix
{
  description = "A Flake with Haxix";
  inputs = {
    # haxix contains all you need for Haxe development
    haxix.url = "github:MadMcCrow/haxix";
  };
  outputs = { self, haxix, ... }@inputs:
    let
      # supported systems
      systems = [ "x86_64-linux" "aarch64-linux" ];

      # default system-agnostic flake implementation :
      flake = system:
        let

          haxix-lib = haxix.lib."${system}";
          # heaps game example :
          my-project = haxix-lib.mkHeapsGame {
            src = self;
            name = "my-project";
            version = "0.0.1-alpha";
            debug = false;
            release = false;
          };
        in {
          # implement your flake here ;)
          packages."${system}" = {
            inherit my-project;
            default = my-project;
          };
        };

      # gen for all systems :
    in foldl' (x: y: godot-flake.inputs.nixpkgs.lib.recursiveUpdate x y) { }
    (map flake systems);
}
