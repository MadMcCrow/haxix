{ lib, haxe, src, version, ... }:
haxe.buildHaxelib {
  inherit src version;
  pname = "haxe-formatter";
  meta = {
    homepage = "https://github.com/HaxeCheckstyle/haxe-formatter";
    description = "A Haxe tool to format haxe code";
    license = lib.licenses.mit;
  };
}
