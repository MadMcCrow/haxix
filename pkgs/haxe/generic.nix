# haxe/generic.nix
# build haxe from sources
{
  version,
  src,
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
haxe.overrideAttrs (previousAttrs: {
  inherit version;
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
        version = "0.5.12";
        src = fetchurl {
          url = "https://github.com/aantron/luv/releases/download/0.5.12/luv-0.5.12.tar.gz";
          sha256 = "sha256-dp9qCIYqSdROIAQ+Jw73F3vMe7hnkDe8BgZWImNMVsA=";
        };

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
