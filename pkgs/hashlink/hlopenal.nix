# openal library for hashlink-latest
{ haxe, hl }:
haxe.buildHaxelib {
  version = hl.version;
  pname = "openal";
  src = "${hl.src}/libs/openal";
  meta = hl.meta // { description = "openal support for hashlink-latest"; };
}
