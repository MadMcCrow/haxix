# pkgs/shell.nix
# Dev Shell for the whole gang
# we might wanna split into a multitude of shells
{
  mkShell,
  statix,
  deadnix,
  nixfmt-rfc-style,
  haxe,
  format,
  hxcpp,
  hashlink,
  hlsdl,
  hlopenal,
  heaps,
  formatter,
  haxefmt,
  dox,
  raylib,
  raylib-hx,
  hxp,
  lime,
  neko,
  ...
}:
let
  # helper : 
  haxeShell =
    inputs:
    mkShell {
      buildInputs = [
        haxe
        haxefmt
        formatter
        dox
      ] ++ inputs;
    };
in
rec {
  # for working on haxix :
  default = haxeShell [
    statix
    deadnix
    nixfmt-rfc-style
  ];

  heapsShell = haxeShell [
    format
    hashlink
    hlsdl
    hlopenal
    heaps
  ];

  limeShell = haxeShell [
    neko
    hxp
    lime
  ];

  raylibShell = haxeShell [
    raylib
    raylib-hx
    hxcpp
  ];
}
