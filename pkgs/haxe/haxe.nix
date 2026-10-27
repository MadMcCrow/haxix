# haxe.nix
# build haxe from sources
{
  stdenv,
  lib,
  fetchurl,
  pkgs,
  ocaml-ng,
  zlib,
  pcre2,
  neko,
  mbedtls_2,
  darwin,
  callPackage,
  self,
  ...
}:
let
  # pinned sources
  sources = import ../_npins;
  pin = sources.haxe;

  # build without our nix helper
  # we need to specify pkgs instead of "haxe" directly to avoid infrec
  haxe-unlib = pkgs.haxe.overrideAttrs (previousAttrs: {
  version = pin.version ;
  src = pin;
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
    ++ (lib.optional stdenv.hostPlatform.isDarwin darwin.apple_sdk.frameworks.Security);

  # add support for lib.getExe
  meta = previousAttrs.meta // {
    mainProgram = "haxe";
  };
});
in haxe-unlib //
  # add  the library to the package
  ( callPackage ( self + "/lib/haxelib.nix" ) { haxe = haxe-unlib; inherit self; } )
