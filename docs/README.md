# Haxix

A flake to build and run games made with [heaps.io](https://heaps.io/) and possibly other haxe game engines (raylib, armory, ...) in the future.

## Usage

Here's a quick code example.
```nix
{
    # Add haxix to your flake inputs :
    inputs.haxix.url = "github:MadMcCrow/haxix";
    ...
    # and now you can access all our packages and functions
    haxePkgs = haxix.legacyPackages."${system}";
}
```
for more details, look at the various templates, for example the [heaps template](../templates/)

you can instantiate it in any folder with :
```
nix flake init -t github:MadMcCrow/haxix#heaps
```

You can use `nix flake show --legacy` to see all the packages haxix provides

## TODO

See [TODO.md](./TODO.md). these are the most likely things to be added to the project.

## Contribute

Any [contribution](./CONTRIBUTING.md) welcome. You can contribute on features, documentation, or bug fixes.

## Licence

Licensed under [MIT](./Licence.md)

## Authors

See [AUTHORS](./AUTHORS.md) for the complete list of people who helped make haxix.

## Status

![check](https://github.com/MadMcCrow/haxix/actions/workflows/check.yml/badge.svg?branch=main)
