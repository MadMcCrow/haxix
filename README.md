# haxix

a flake to build and run games made with [heaps.io](https://heaps.io/)

# usage

Add this to your flake

```nix
{
    inputs = {
        haxix.url = "github:MadMcCrow/haxix"
        # not mandatory but should work just fine :
        # haxix.inputs.nixpkgs.follows = "nixpkgs";
        ...
    };

    outputs = {self, nixpkgs, haxix, ...} : {
        packages."x86_64-linux".default = haxix.buildGame {
            name = "my-game";
            src = self;
            version = "0.0.1-alpha";
            debug = false;
            release = false;
        };
    };
}

```

# TODO:

 - [ ] create self contained binary to export everything as one binary
 - [ ] better documentation
 - [ ] support packaging resources

# Licence
Licensed under [MIT](Licence.md)