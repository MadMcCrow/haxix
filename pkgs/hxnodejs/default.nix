# hxnodejs
# Extern type definitions for Node.JS
{ haxe, fetchFromGitHub, ... } :
{
  hxnodejs = haxe.buildHaxelib rec {
    name = "hxnodejs";
    version = "12.2.0";
    src = fetchFromGitHub {
      repo = name;
      owner= "HaxeFoundation";
      rev = "c9450595b2337587bcdaeacf159019531925f25d";
      sha256 = "";
    };
  };
}