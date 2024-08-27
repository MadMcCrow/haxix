# helper to build libraries
# this is a copy of what nixpkgs does, because it is not exposed to uss
{
  lib,
  stdenv,
  fetchzip,
  haxe,
  neko,
  ...
}:
let
  # install command
  withCommas = lib.replaceStrings [ "." ] [ "," ];
  installHaxelib =
    {
      pname,
      version,
      files ? "*",
    }:
    ''
      mkdir -p "$out/lib/haxe/${withCommas pname}/${withCommas version}"
      echo -n "${version}" > $out/lib/haxe/${withCommas pname}/.current
      cp -dpR ${files} "$out/lib/haxe/${withCommas pname}/${withCommas version}/"
    '';
in
{
  # used in hashlink-latest :
  inherit installHaxelib;

  # from nixpkgs
  buildHaxelib =
    {
      pname,
      version ? haxe.version,
      sha256 ? "",
      ...
    }@attrs:
    stdenv.mkDerivation (
      attrs
      // {
        name = attrs.name or "${pname}-${version}";
        inherit version;
        buildInputs =
          (attrs.buildInputs or [ ])
          ++ [ haxe ]
          ++ [
            haxe
            neko
          ]; # for setup-hook.sh to work
        src =
          attrs.src or (fetchzip rec {
            name = "${pname}-${version}";
            url = "http://lib.haxe.org/files/3.0/${withCommas name}.zip";
            inherit sha256;
            stripRoot = false;
          });

        installPhase =
          attrs.installPhase or ''
            runHook preInstall
            (
              if [ $(ls $src | wc -l) == 1 ]; then
                cd $src/* || cd $src
              else
                cd $src
              fi
              ${
                installHaxelib {
                  inherit pname version;
                  files = attrs.files or "*";
                }
              }
            )
            runHook postInstall
          '';

    doInstallCheck = true;
    installCheckPhase = ''
        ls $out/lib/haxe/${pname}
      '';

        meta = {
          homepage = "http://lib.haxe.org/p/${pname}";
          license = lib.licenses.free;
          platforms = lib.platforms.all;
          description = throw "please write meta.description";
        } // (attrs.meta or { });
      }
    );
}
