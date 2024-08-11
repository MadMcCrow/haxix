# lime/default.nix
# provide lime as well as function to work with it
{ callPackage, ... }@args:
let
  lime = callPackage ./generic.nix args;
  lib = callPackage ./lib.nix (args // { inherit lime; });
in
{
  lime = lime // lib;
}
