# pkgs/shell.nix
# Dev Shell for the whole gang
# we might wanna split into a multitude of shells
{
  mkShell,
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
haxeShell = inputs : mkShell {
  buildInputs = [haxe haxefmt formatter dox] ++ inputs;
};
in
rec {
  default = haxeShell [];

  heapsShell = haxeShell [ format hashlink hlsdl hlopenal heaps ];

  limeShell = haxeShell [ neko hxp lime ];

  raylibShell = haxeShell [ raylib raylib-hx hxcpp ];
}
