# hxnodejs
# Extern type definitions for Node.JS
{ haxe, fetchFromGitHub, ... } :
let
  name = "hxnodejs";
  sources = import ../_npins;
in
{
  hxnodejs = haxe.buildHaxelib {
    inherit name;
    src = sources.${name};
    version = "12.2.0"; # last known version was 12.1.0
  };
}
