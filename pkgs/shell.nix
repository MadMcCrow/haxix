# make shell with every thing
{ mkShell, haxe, hashlink-latest, format, hxcpp, heaps, formatter, haxefmt, dox, raylib
, raylib-hx, neko, ... }:
mkShell {
  buildInputs = [
    haxe
    hashlink-latest
    format
    hxcpp
    heaps
    formatter
    haxefmt
    dox
    raylib
    raylib-hx
    neko
  ];
}
