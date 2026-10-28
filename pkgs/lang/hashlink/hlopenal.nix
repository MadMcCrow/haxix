# openal library for hashlink
{ haxe, hashlink, ... }:
haxe.buildHaxelib {
  inherit (hashlink) version;
  pname = "hlopenal";
  src = "${hashlink.src}/libs/openal";
  meta = {
    inherit (hashlink.meta) license homepage;
    description = "openal support for hashlink";
  };
}
