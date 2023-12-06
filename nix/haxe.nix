# haxe.nix
# a collection of functions and derivation to have custom haxe support
{
  pkgs,
  haxe,
}: let
  ocamlDependencies = ocamlPkgs:
    with ocamlPkgs; [
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
      (luv.overrideAttrs (final: prev: {
        version = "0.5.12";
        src = pkgs.fetchurl {
          url = "https://github.com/aantron/luv/releases/download/0.5.12/luv-0.5.12.tar.gz";
          sha256 = "sha256-dp9qCIYqSdROIAQ+Jw73F3vMe7hnkDe8BgZWImNMVsA=";
        };
      }))
      extlib
      stdlib-shims
    ];

  generic = {
    version,
    src,
    ocaml-ng,
  }:
    pkgs.haxe.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      buildInputs =
        (with pkgs; [zlib pcre2 neko mbedtls_2])
        ++ (ocamlDependencies ocaml-ng)
        ++ (pkgs.lib.optional (pkgs.stdenv.isDarwin)
          pkgs.darwin.apple_sdk.frameworks.Security);
    });
in {
  # HAXE : flake latest version
  haxe_latest = generic {
    version = "development";
    src = haxe;
    ocaml-ng = pkgs.ocaml-ng.ocamlPackages_4_08;
  };
}
