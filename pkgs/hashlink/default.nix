# hashlink-latest/default.nix
#   hashlink-latest is a virtual machine that can be targeted
#   when building haxe code
{ stdenv, buildEnv, callPackage, inputs, haxe, ... }@args:
let
  version = "1.14";
  # hashlink-latest is different depending on the platform
  hl = (if stdenv.isDarwin then
    callPackage ./hl-darwin.nix
  else
    callPackage ./hl.nix) (args // { inherit version; });
in {
  hashlink = hl;
  #buildEnv {
  #name = "hashlink-latest";
  #paths = [
#    (import ./hlsdl { inherit haxe hl; })
#    (import ./hlopenal { inherit haxe hl; })
#  ];
#};
}
