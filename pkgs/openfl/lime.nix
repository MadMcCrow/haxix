# lime/generic.nix
# provide latest lime
args@{ pkgs, lib, haxe, format, hxp, self, ... }:
let
lime-unlib = haxe.buildHaxelib {
  pname = "lime";
  version = "8.1.3";
  sha256 = "sha256-bOwe+jNymk+5liOv0eoFlNtrYxLBlxivntFnrQDDgKU=";
  meta = {
    homepage = "https://lime.openfl.org/";
    description = "A foundational Haxe framework for cross-platform development";
    license = lib.licenses.mit;
  };
};
in lime-unlib // (pkgs.callPackage (self + "/lib/limelib.nix") ({lime = lime-unlib;} // args))
