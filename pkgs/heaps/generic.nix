# heaps/generic.nix
# Build heaps games with nix 
# TODO : remove function mkGame from module (move to separate "lib" module)
{ src, version, haxePackages, haxe, format, hashlink, SDL2, openal, ... }:
haxe.buildHaxelib {
  inherit src version;
  libname = "heaps";
  buildInputs = [ haxe format hashlink SDL2 openal ];
  meta = haxePackages.heaps.meta;
}
