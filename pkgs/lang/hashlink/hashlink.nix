{stdenv, callPackage, haxe, libpng, hashlink, ...} @args :
let
  # pinned sources
  sources = import ../../_npins;
  pin = sources.hashlink;
  inherit (pin) version;
  # get the correct hashlink for the platform :
  myHashlink = if stdenv.hostPlatform.isDarwin then (callPackage ./_darwin.nix args ) else hashlink;
in
# implement our special sauce (same for all platforms)
myHashlink.overrideAttrs ( finalAttrs: previousAttrs: {
    inherit version;
    src = pin;
    buildInputs = previousAttrs.buildInputs ++ [ libpng ];
    postInstall = ''
      ${haxe.installHaxelib {
        pname = "${finalAttrs.pname}";
        files = "other/haxelib/*";
        inherit version;
      }}
    '';
    doInstallCheck = true;
    installCheckPhase = ''
        ls $out/lib/haxe/hashlink
        $out/bin/hl --version
      '';
  })
