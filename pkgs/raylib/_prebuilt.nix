# raylib/_prebuilt.nix
# TODO : make prebuild work for linux and MacOS
{
  stdenvNoCC,
  fetchzip,
  inputs,
  ...
}:
let
  raylib_generic =
    {
      version,
      file,
      hash,
    }:
    stdenvNoCC.mkDerivation {
      inherit version;
      # source is pre-build
      src = fetchzip {
        inherit hash;
        url = "https://github.com/raysan5/raylib/releases/download/${version}/${file}";
      };
      # package
      pname = "raylib";
      name = "raylib-${version}";
      # install library to lib folder
      installPhase = ''
        mkdir -p $out
        cp -r lib $out/
        cp -r include $out/
        export RAYLIB_C_PATH=$out
      '';
      # meta
      meta = pkgs.raylib.meta // {
        platforms = [ stdenv.system ];
      };
    };
in
rec {
  # raylib library
  raylib = raylib_generic (
    if stdenv.isLinux then
      {
        version = "5.0";
        file = "raylib-5.0_linux_amd64.tar.gz";
        hash = "";
      }
      else {

      }
}
