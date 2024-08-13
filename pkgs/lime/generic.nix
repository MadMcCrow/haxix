# lime/generic.nix
# provide latest lime
# TODO : add as flake input ?
{ lib, haxe, ... }:
haxe.buildHaxelib {
  pname = "lime";
  version = "8.1.3";
  sha256 = "sha256-bOwe+jNymk+5liOv0eoFlNtrYxLBlxivntFnrQDDgKU=";
  meta = {
    homepage = "https://lime.openfl.org/";
    description = "A foundational Haxe framework for cross-platform development";
    license = lib.licenses.mit;
  };
}
