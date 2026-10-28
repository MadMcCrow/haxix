# lib/raylib.nix
# helper function
{raylib, raylib-hx, ... } :
{
  buildRaylibHxGame = {
      src,
      buildHxml ? "Build.hxml",
      ...
    }@args:
    stdenv.mkDerivation (
      {
        inherit src;
        unpackPhase = ''
          cp -r $src/* ./
        '';
        # build with haxe compiler
        buildPhase = ''
          ${haxe}/bin/haxe ${buildHxml}
        '';
        buildInputs = [
          raylib
          raylib-hx
        ];
      }
      // args
    );
}
