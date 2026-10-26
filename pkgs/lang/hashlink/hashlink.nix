{stdenv, callPackage, haxe, libpng, hashlink, version, inputs, ...} @args :
let
  # pinned sources
  sources = import ../../_npins;
  pin = sources.hashlink;

  # get the correct hashlink for the platform :
  myHashlink = if stdenv.isDarwin then (callPackage ./_darwin.nix args ) else hashlink;
# implement our special sauce (same for all platforms)
in myHashlink.overrideAttrs ( finalAttrs: previousAttrs: {
    inherit (pin) version;
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
