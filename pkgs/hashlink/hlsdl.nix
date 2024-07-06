# HLSDL library for hl
{ haxe, hl }:
haxe.buildHaxelib {
  version = hl.version;
  pname = "hlsdl";
  src = "${hl.src}/libs/sdl";
  meta = hl.meta // { description = "sdl2 support for hl"; };
}
