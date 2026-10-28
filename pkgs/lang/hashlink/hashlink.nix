{pkgs, lib, stdenv, callPackage, haxe, libpng, ...} @args :
let
  # pinned sources
  sources = import ../../_npins;
  pin = sources.hashlink;
  inherit (pin) version;
  # get the correct hashlink for the platform :
  myHashlink = if stdenv.hostPlatform.isDarwin then (callPackage ./_darwin.nix args ) else pkgs.hashlink;
in
# implement our special sauce (same for all platforms)
myHashlink.overrideAttrs ( finalAttrs: previousAttrs: {
    inherit version;
    src = pin;
    buildInputs = previousAttrs.buildInputs ++ [ libpng ];

    postInstall = (previousAttrs.postInstall or "") + ''
        (
          cd "$NIX_BUILD_TOP/source"
          ${haxe.installHaxelib {
            pname = finalAttrs.pname;
            files = "other/haxelib/*";
            inherit version;
          }}
        )
      '';
    doInstallCheck = true;
    installCheckPhase = ''
        ls $out/lib/haxe/hashlink
        $out/bin/hl --version
      '';
      meta = previousAttrs.meta // {
         platforms = lib.platforms.linux ++ lib.platforms.darwin ++ ["x86_64-darwin"];
       };
  })
