{ lib, src, haxe, version, ... }:
haxe.buildHaxelib {
  inherit src version;
  pname = "formatter";
  meta = {
    homepage = "https://github.com/HaxeCheckstyle/haxe-formatter";
    description = "A Haxe tool to format haxe code";
    license = lib.licenses.mit;
  };
}
