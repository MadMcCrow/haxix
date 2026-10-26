# haxe.nix
# build haxe from sources
{
  stdenv,
  lib,
  fetchurl,
  haxe,
  ocaml-ng,
  zlib,
  pcre2,
  neko,
  mbedtls_2,
  darwin,
  ...
}:
let
  sources = import ../_npins;
  pin = sources.haxe;
in
haxe.overrideAttrs (previousAttrs: {
  version = pin.version ;
  src = lib.head (lib.splitString "-" pin.version);
  buildInputs =
    previousAttrs.buildInputs
    ++ [
      zlib
      pcre2
      neko
      mbedtls_2
    ]
    ++ (with ocaml-ng.ocamlPackages_4_14; [
      ocaml
      findlib
      sedlex
      xml-light
      ptmap
      camlp5
      sha
      dune_3
      ipaddr
      camlp-streams
      terminal_size
      (luv.overrideAttrs {
        inherit (sources.${luv}) version;
        src = sources.${luv};
      })
      extlib
      stdlib-shims
    ])
    ++ (lib.optional stdenv.isDarwin darwin.apple_sdk.frameworks.Security);

  # add support for lib.getExe
  meta = previousAttrs.meta // {
    mainProgram = "haxe";
  };
})
