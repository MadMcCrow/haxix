# hashlink/default.nix
#   hashlink is a virtual machine that can be targeted
#   when building haxe code
{ stdenv, callPackage, inputs, ... }: {
  hashlink = (if stdenv.isDarwin then
    callPackage ./darwin.nix
  else
    callPackage ./generic.nix) {
      version = "1.14";
      src = inputs.hashlink;
    };
}
