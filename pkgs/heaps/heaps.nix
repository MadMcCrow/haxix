# heaps.nix
# HEAPS game engine
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
haxelib.buildHaxelib {
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
