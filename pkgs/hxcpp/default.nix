# hxcpp/default.nix
# hxcpp is the cpp exporter for haxe 
{ callPackage, inputs, ... }:
{
  hxcpp = callPackage ./generic.nix {
    version = "4.3.14";
    src = inputs.hxcpp;
  };
}
