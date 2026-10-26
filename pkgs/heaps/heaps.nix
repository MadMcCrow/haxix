# heaps.nix
# HEAPS game engine
{
  self,
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
let
  # pinned sources
  pname = "heaps";
  sources = import ../_npins;
  pin = sources.${pname};
  heaps-unlib =
(haxelib.buildHaxelib {
  # get from pin
  src = pin;
  inherit (pin) version;
  inherit pname;

  buildInputs = [
    format
    hashlink
    SDL2
    openal
    hlsdl
    hlopenal
  ];

  inherit (haxePackages.heaps) meta;
});
in
# append our helper function
heaps-unlib // (pkgs.callPackage (self + "/heapslib.nix" {heaps = heaps-unlib; inherit haxe;})
