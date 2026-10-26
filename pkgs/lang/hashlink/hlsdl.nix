# HLSDL library for hl
{ haxe, hashlink, ... }:
haxe.buildHaxelib {
  inherit (hashlink) version;
  pname = "hlsdl";
  src = "${hashlink.src}/libs/sdl";
  meta = {
    inherit (hashlink.meta) license homepage;
    description = "sdl2 support for hashlink";
  };
}
