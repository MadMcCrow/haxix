# dox.nix
# a haxe library for creating beautiful docs
{ callPackage, ... }@args:
let dox = callPackage ./generic.nix (args // { version = "1.6.0"; });
in { dox = dox // (callPackage ./lib.nix (args // { inherit dox; })); }
