# haxefmt/formatter.nix
# haxefmt is a formatting tool to format haxe code
# the library
{
  lib,
  haxe,
  ...
}:
let
pname = "formatter";
sources = import ../_npins;
pin = sources."haxe-formatter";
in

 haxe.buildHaxelib {
   pname = lib.toLower pname;
   inherit (pin) version;
   src = pin;

   meta = {
     homepage = "https://github.com/HaxeCheckstyle/haxe-formatter";
     description = "A Haxe tool to format haxe code";
     license = lib.licenses.mit;
   };
 }
