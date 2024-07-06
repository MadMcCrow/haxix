# raylib/raylib-hx.nix
# Raylib bindings for haxe
{ version, inputs, lib, stdenvNoCC, haxe, raylib, ... }:

stdenvNoCC.mkDerivation {
  inherit version;
  src = inputs.raylib-hx;
  pname = "raylib-hx";
  buildInputs = [ raylib ]; # maybe add haxe
  # install
  installPhase = ''
    runHook preInstall
    (
      if [ $(ls $src | wc -l) == 1 ]; then
        cd $src/* || cd $src
      else
        cd $src
      fi
      ${
        haxe.installHaxelib {
          pname = "raylib-hx";
          files = "*";
          inherit version;
        }
      }
    )
    runHook postInstall
  '';

  meta = {
    homepage = "https://github.com/foreignsasquatch/raylib-hx";
    license = lib.licenses.zlib;
    platforms = lib.platforms.all;
    description =
      "Haxe bindings for raylib, a simple and easy-to-use library to learn videogame programming.";
  };
}

