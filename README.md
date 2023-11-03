# Haxix

a flake to build and run games made with [heaps.io](https://heaps.io/)

# Usage

Add this to your flake

```nix
{
    inputs = {
        haxix.url = "github:MadMcCrow/haxix";
        # not mandatory but should work just fine :
        # haxix.inputs.nixpkgs.follows = "nixpkgs";
        ...
    };

    outputs = {self, nixpkgs, haxix, ...} : {
        packages."x86_64-linux" = {
            default = haxix.lib."x86_64-linux".heaps.buildGame {
                name = "my-game";
                src = self; # or the folder containing the src folder
                version = "0.0.1-alpha";
                debug = false;   # set to true to have debug symbols
                release = false; # set to true for compiled to C
            };
        };
    };
}

```

# TODO

 - [ ] support packaging resources
 - [ ] support other haxe game engines
 - [ ] add option for custom compile.hxml
 - [ ] cache build output
 - [ ] add flake checks
 - [ ] add flake templates

# Contribute

Any contribution welcome. 

# Licence
Licensed under [MIT](Licence.md)
