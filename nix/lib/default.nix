{ callPackage, ... }  @args :
{
  mkHaxeDoc = callPackage ./mkhaxedoc.nix args;
  mkHaxelib = callPackage ./mkhaxelib.nix args;
  mkHeaps   = callPackage ./mkheaps.nix   args; 
}