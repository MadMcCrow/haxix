{stdenv, callPackage, haxe, libpng, hashlink, version, inputs, ...} @args :
let 
  # get the correct hashlink for the platform :
  myHashlink = if stdenv.isDarwin then (callPackage ./darwin.nix args ) else hashlink;
# implement our special sauce (same for all platforms)
in myHashlink.overrideAttrs ( finalAttrs: previousAttrs: {
    inherit version;
    src = inputs.hashlink;
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