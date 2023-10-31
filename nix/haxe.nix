# haxe.nix
# a collection of functions and derivation to have custom haxe support
# you can update the version in "alpha" with the sha and rev from flake.lock
{ pkgs, inputs }:
let
  withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];

  # install lib command
  installLibHaxe = { libname, version, files ? "*" }: ''
    mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
    echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
    cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${
      withCommas version
    }/"
  '';

  my_haxe = { version, src, ocaml-ng }:
    pkgs.haxe.overrideAttrs (finalAttrs: previousAttrs: rec {
      inherit version src;
      buildInputs = let
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
      in (with pkgs; [ zlib pcre2 neko mbedtls_2 ]) ++ ocamlDependencies
      ++ (pkgs.lib.optional (pkgs.stdenv.isDarwin)
        pkgs.darwin.apple_sdk.frameworks.Security);
    });

  # Custom HL with libraries for haxelib added
  my_hashlink = { version, src }:
    pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      postInstall = (previousAttrs.postInstall or "") + ''
        ${installLibHaxe {
          libname = "${finalAttrs.pname}";
          files = "other/haxelib/*";
          inherit version;
        }}
        ${installLibHaxe {
          libname = "hlsdl";
          files = "libs/sdl/*";
          inherit version;
        }}
      '';
    });

  my_format = { version, src }:
    pkgs.haxePackages.format.overrideAttrs
    (finalAttrs: previousAttrs: { inherit version src; });

in {

  # HAXE : flake latest version
  haxe_latest = my_haxe {
    version = "development";
    src = inputs.haxe; # dependancy from flake
    ocaml-ng = pkgs.ocaml-ng.ocamlPackages_4_08;
  };

  # HASHLINK : flake latest version
  hashlink_latest = my_hashlink {
    src = inputs.hashlink;
    version = "latest";
  };

  # FORMAT : alpha fixed version
  format_latest = my_format {
    src = inputs.haxe_format;
    version = "latest";
  };

  # helper to build libraries
  # this is a copy of what nixpkgs does, because it is not exposed to uss
  buildHaxeLib = { libname, version, sha256 ? "", meta, ... }@attrs:
    pkgs.stdenv.mkDerivation (attrs // {
      name = attrs.name or "${libname}-${version}";

      buildInputs = (attrs.buildInputs or [ ])
        ++ (with pkgs; [ haxe neko ]); # for setup-hook.sh to work
      src = attrs.src or (pkgs.fetchzip rec {
        name = "${libname}-${version}";
        url = "http://lib.haxe.org/files/3.0/${withCommas name}.zip";
        inherit sha256;
        stripRoot = false;
      });

      installPhase = attrs.installPhase or ''
        runHook preInstall
        (
          if [ $(ls $src | wc -l) == 1 ]; then
            cd $src/* || cd $src
          else
            cd $src
          fi
          ${installLibHaxe { inherit libname version; }}
        )
        runHook postInstall
      '';

      meta = {
        homepage = "http://lib.haxe.org/p/${libname}";
        license = pkgs.lib.licenses.free;
        platforms = pkgs.lib.platforms.all;
        description = throw "please write meta.description";
      } // attrs.meta;
    });
}
