# raylib.nix
# raylib bindings for haxe
{pkgs, raylib-hx, raylib, haxelib, hxcpp_latest } : 
let
  inherit (pkgs.lib) optionals;
  isDarwin = pkgs.stdenv.isDarwin;

  raylib_latest = pkgs.stdenv.mkDerivation rec {
  pname = "raylib";
  version = "4.5.0";
  src = raylib;
  nativeBuildInputs = [ pkgs.cmake ];
  # TODO: Darwin
  buildInputs = with pkgs; (optionals (!isDarwin) [
    mesa glfw libXi libXcursor libXrandr libXinerama
    alsa-lib libpulseaudio]) ++ (optionals isDarwin [
      darwin.xcode
      darwin.cf-private
    ]);

  propagatedBuildInputs =  with pkgs; (optionals (!isDarwin)
    [ libGLU libX11 ]);
  # https://github.com/raysan5/raylib/wiki/CMake-Build-Options
  cmakeFlags = [
    # "-DUSE_EXTERNAL_GLFW=ON"
    "-DBUILD_EXAMPLES=OFF"
    "-DCUSTOMIZE_BUILD=1"
    "-DINCLUDE_EVERYTHING=ON"
    "-DBUILD_SHARED_LIBS=ON"
  ];

  # fix libasound.so/libpulse.so not being found
  #preFixup = ''
  #  ${lib.optionalString alsaSupport "patchelf --add-needed ${alsa-lib}/lib/libasound.so $out/lib/libraylib.so.${version}"}
  #  ${lib.optionalString pulseSupport "patchelf --add-needed ${libpulseaudio}/lib/libpulse.so $out/lib/libraylib.so.${version}"}
  #'';
  meta = with pkgs.lib; {
    description = "A simple and easy-to-use library to enjoy videogames programming";
    homepage = "https://www.raylib.com/";
    license = licenses.zlib;
    platforms = pkgs.lib.platforms.all;
    changelog = "https://github.com/raysan5/raylib/blob/${version}/CHANGELOG";
  };
  };

  generic = {version, src} : haxelib.mkHaxelib {
    inherit version src;
    buildInputs = [hxcpp_latest];
    libname = "raylib-hx";
    meta = {
      description = "Raylib bindings for Haxe";
      license = pkgs.lib.licenses.zlib;
      platforms = pkgs.lib.platforms.all;

    };
  };

  raylibHaxe_latest = generic { src = raylib-hx; version = "latest"; };

in
{
  inherit raylibHaxe_latest;
  mkGame = {src, ...} @args : pkgs.stdenv.mkDerivation (args //{
    inherit src;
    buildInputs = (args.buildInputs or []) ++ [raylibHaxe_latest];
  });
}
