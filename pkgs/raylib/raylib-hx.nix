# raylib/raylib-hx.nix
# Raylib bindings for haxe
{
  lib,
  stdenvNoCC,
  haxe,
  raylib,
  ...
}:
let
  # npins sources
  sources = (import ../_npins);

  # raylib override
  raylib = let
    pin = sources.raylib; in raylib.overrideAttrs {
    inherit (pin) version;
    src = pin;
  };
  # our pin
  pin = sources.raylib-hx;

in stdenvNoCC.mkDerivation {
  name = "raylib-hx";
  inherit (pin) version;
  src = pin;

  buildInputs = [ raylib haxe ];
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
          inherit (pin) version;
        }
      }
    )
    runHook postInstall
  '';

  meta = {
    homepage = "https://github.com/foreignsasquatch/raylib-hx";
    license = lib.licenses.zlib;
    platforms = lib.platforms.all;
    description = "Haxe bindings for raylib, a simple and easy-to-use library to learn videogame programming.";
  };
}
