# hashlink-latest/default.nix
#   hashlink-latest is a virtual machine that can be targeted
#   when building haxe code
{
  stdenv,
  callPackage,
  haxe,
  ...
}@args:
let
  version = "1.14";
in
rec {
  # three packages 
  hashlink = callPackage (if stdenv.isDarwin then ./hl-darwin.nix else ./hl.nix) (
    args // { inherit version; }
  );
  hlsdl = callPackage ./hlsdl.nix (args // { inherit haxe hashlink; });
  hlopenal = callPackage ./hlopenal.nix (args // { inherit haxe hashlink; });
}
