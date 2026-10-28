# dev 02/09/2024
 - added checks. 

# main 10/08/2024
 - cleaned dead code with deadix and statix
 - added lime (from [this PR](https://github.com/MadMcCrow/haxix/pull/6), big thanks to  @bwkam)
 - improved templates

# main 06/07/2024
- reordered packages to fix dependencies
- respect nix-way to have libraries in flakes
- updated haxe and other packages
- added a tool to find the latest versions of packages

## dev 10/11/2023
- `mkHeapsGame` now require your own `compile.hxml`
- WIP formatter, needs the actual program, not the library
- you can generate docs derivation for Haxe derivations

## main
- build and run Heaps games on linux
- build wih latest Haxe, Heaps, etc.
- MacOS (darwin) support
    - M1 support (no native heaps game, because HL cannot be built in arm64)
- package haxelibs
- Check flake with github action for PRs
- mkHeapsGame support buildInputs
- Added a simple default haxe shell