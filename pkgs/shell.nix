# make shell with every thing
{ mkShell, haxe, format, hxcpp, hashlink, hlsdl, hlopenal, heaps, formatter
, haxefmt, dox, raylib, raylib-hx, neko, ... }:
mkShell {
  buildInputs = [
    haxe
    neko
    hxcpp
    format
    hashlink
    hlsdl
    hlopenal
    heaps
    formatter
    haxefmt
    dox
    raylib
    raylib-hx
  ];
}
