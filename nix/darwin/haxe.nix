# darwin/haxe.nix
# MacOS version of ../haxe.nix
# fix Ocaml deps for M1s 
{ nixpkgs-darwin, haxe }:
let
  # ocaml is broken on M1
  pkgs = import nixpkgs-darwin { system = "x86_64-darwin"; };

  # haxe but for MacOS
  my_haxe = { version, src, ocaml-ng }:
    let
      ocamlDependencies = with ocaml-ng; [
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
            url =
              "https://github.com/aantron/luv/releases/download/0.5.12/luv-0.5.12.tar.gz";
            sha256 = "sha256-dp9qCIYqSdROIAQ+Jw73F3vMe7hnkDe8BgZWImNMVsA=";
          };
        }))
        extlib
        stdlib-shims
      ];
    in pkgs.haxe.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      buildInputs = (with pkgs; [
        zlib
        pcre2
        neko
        mbedtls_2
        darwin.apple_sdk.frameworks.Security
      ]) ++ (ocamlDependencies);
    });

in {

  # HAXE : flake latest version
  haxe_latest = my_haxe {
    version = "development";
    src = haxe;
    ocaml-ng = pkgs.ocaml-ng.ocamlPackages_4_08;
  };
}
