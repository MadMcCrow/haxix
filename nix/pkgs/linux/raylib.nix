# raylib.nix
# raylib bindings for haxe
{ pkgs, inputs, hxcpp }:
let

  stdenv = pkgs.stdenvNoCC;
  withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];

  raylib_generic = { version, file, hash }:
    stdenv.mkDerivation {
      inherit version;
      # source is pre-build
      src = pkgs.fetchzip {
        inherit hash;
        url =
          "https://github.com/raysan5/raylib/releases/download/${version}/${file}";
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
      meta = pkgs.raylib.meta // { platforms = [ stdenv.system ]; };
    };

  raylibhx_generic = { version, src, raylib }:
    stdenv.mkDerivation {
      inherit src;
      name = "raylib-hx-${version}";
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
          mkdir -p "$out/lib/haxe/raylib-hx/${withCommas version}"
          echo -n "${version}" > $out/lib/haxe/raylib-hx/.current
          cp -dpR * "$out/lib/haxe/raylib-hx/${withCommas version}/"
        )
        runHook postInstall
      '';

      meta = {
        homepage = "https://github.com/foreignsasquatch/raylib-hx";
        license = pkgs.lib.licenses.zlib;
        platforms = pkgs.lib.platforms.all;
        description =
          "Haxe bindings for raylib, a simple and easy-to-use library to learn videogame programming.";
      };
    };
in rec {
  # raylib library
  raylib = raylib_generic (if stdenv.isLinux then {
    version = "5.0";
    file = "raylib-5.0_linux_amd64.tar.gz";
    hash = "";
  } else
    import ./darwin/raylib.nix);

  # raylib-haxe-bindings
  raylib-hx = raylibhx_generic {
    version = "5.0.0";
    inherit raylib;
    src = inputs.raylib-hx;
  };
}
