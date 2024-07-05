{ raylib, raylib-hx, haxe, ... }: {
  buildRaylibHxGame = { src, buildHxml ? "Build.hxml", ... }@args:
    pkgs.stdenv.mkDerivation ({
      inherit src;
      unpackPhase = ''
        cp -r $src/* ./
      '';
      # build with haxe compiler
      buildPhase = ''
        ${haxe}/bin/haxe ${compileHxml}
      '';
    } // args);
}
