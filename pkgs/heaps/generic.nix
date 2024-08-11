# heaps/generic.nix
# Build heaps games with nix 
# TODO : remove function mkGame from module (move to separate "lib" module)
{
  src,
  version,
  haxePackages,
  haxe,
  format,
  hashlink,
  hlsdl,
  hlopenal,
  SDL2,
  openal,
  ...
}:
haxe.buildHaxelib {
  inherit src version;
  pname = "heaps";
  buildInputs = [
    format
    hashlink
    SDL2
    openal
    hlsdl
    hlopenal
  ];
  inherit (haxePackages.heaps) meta;
}
