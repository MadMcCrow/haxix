# hxnodejs
# Extern type definitions for Node.JS
{ lib, haxe, fetchFromGitHub, ... } :
let
  pname = "hxnodejs";
  sources = import ../_npins;
in haxe.buildHaxelib {
    inherit pname;
    src = sources.${pname};
    version = "12.2.0"; # last known version was 12.1.0
    meta = {
      description = "Extern definitions for node.js";
      license = lib.licenses.mit;
    };
  }
