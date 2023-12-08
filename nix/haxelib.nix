# helper to build libraries
# this is a copy of what nixpkgs does, because it is not exposed to us
{pkgs}: let
  # install command
  withCommas = pkgs.lib.replaceStrings ["."] [","];
  installHaxeLib = {
    libname,
    version,
    files ? "*",
  }: ''
    mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
    echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
    cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${
      withCommas version
    }/"
  '';
in {
  inherit installHaxeLib;

  mkHaxelib = {
    libname,
    version,
    sha256 ? "",
    ...
  } @ attrs:
    pkgs.stdenv.mkDerivation (attrs
      // {
        name = attrs.name or "${libname}-${version}";

        buildInputs =
          (attrs.buildInputs or [])
          ++ (with pkgs; [haxe neko]); # for setup-hook.sh to work
        src =
          attrs.src
          or (pkgs.fetchzip rec {
            name = "${libname}-${version}";
            url = "http://lib.haxe.org/files/3.0/${withCommas name}.zip";
            inherit sha256;
            stripRoot = false;
          });

        installPhase =
          attrs.installPhase
          or ''
            runHook preInstall
            (
              if [ $(ls $src | wc -l) == 1 ]; then
                cd $src/* || cd $src
              else
                cd $src
              fi
              ${
              installHaxeLib {
                inherit libname version;
                files = attrs.files or "*";
              }
            }
            )
            runHook postInstall
          '';

        meta =
          {
            homepage = "http://lib.haxe.org/p/${libname}";
            license = pkgs.lib.licenses.free;
            platforms = pkgs.lib.platforms.all;
            description = throw "please write meta.description";
          }
          // (attrs.meta or {});
      });
}
