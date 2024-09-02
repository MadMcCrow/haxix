# hashlink-latest/default.nix
#   hashlink-latest is a virtual machine that can be targeted
#   when building haxe code
{
  stdenv,
  callPackage,
  haxe,
  ...
}@args:
rec {
  # three packages 
  hashlink = callPackage ./generic.nix (args // {version = "1.14";} );
  hlsdl = callPackage ./hlsdl.nix (args // { inherit haxe hashlink; });
  hlopenal = callPackage ./hlopenal.nix (args // { inherit haxe hashlink; });
}
