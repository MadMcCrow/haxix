# import all shared packages :
{callPackage, ...} @args : 
{
  haxe = callPackage (import ./haxe.nix) args;
}