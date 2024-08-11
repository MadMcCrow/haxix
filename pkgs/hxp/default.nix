# hxp/default.nix
# provide openfl/hxp
# TODO : use flake input ?
{ lib, haxe, ... }:
{
  hxp = haxe.buildHaxelib {
    pname = "hxp";
    version = "1.3.0";
    sha256 = "sha256-h1vziyWzJUk/pHGkkMO1gMrs38rdhKjp9HYi6+QBbCM=";
    meta = {
      homepage = "https://github.com/openfl/hxp";
      description = "Write scripts in Haxe, and execute them on Windows, macOS or Linux";
      license = lib.licenses.mit;
    };
  };
}
