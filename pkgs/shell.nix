# make shell with every thing
{ mkShell, haxe, hashlink, format, hxcpp, heaps, formatter, haxefmt, dox, raylib
, raylib-hx, neko, ... }:
mkShell {
  buildInputs = [
    haxe
    hashlink
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
