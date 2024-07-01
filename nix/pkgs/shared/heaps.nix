# heaps.nix
# Build heaps games with nix 
# TODO : remove function mkGame from module (move to separate "lib" module)
{ pkgs, inputs, haxe, format, haxelib, hashlink }:
let
  heaps = haxelib.mkHaxelib {
    version = "1.11.0";
    libname = "heaps";
    src = inputs.heaps;
    meta = pkgs.haxePackages.heaps.meta;
  };

  # the whole heaps.io engine
  dependancies = [ haxe format heaps hashlink pkgs.SDL2 pkgs.openal ];

in {
  inherit heaps;

  # The heaps game recipe
  mkGame = { compileHxml ? "compile.hxml", ... }@args:
    let
      name = args.pname or args.name;
      # disable HL/C on MacOS M1
      DoHLC = if pkgs.stdenv.isDarwin then "false" else "true";
    in pkgs.stdenv.mkDerivation (args // {
      # build inputs
      buildInputs = (args.buildInputs or [ ]) ++ dependancies;
      nativeBuildInputs = (args.nativeBuildInputs or [ ]) ++ dependancies;
      # copy source and the hxml
      unpackPhase = ''
        cp -r $src/* ./
      '';
      # build with haxe compiler
      buildPhase = ''
        ${haxe}/bin/haxe ${compileHxml}
        OUTHL=$(cat ${compileHxml} | grep '^-hl *[[:graph:]]*.hl' || true)
        OUTHL=$(echo $OUTHL | sed 's/-hl[[:space:]]*//g')
        OUTC=$(cat ${compileHxml} | grep '^-hl *[[:graph:]]*.c' || true)
        OUTC=$(echo $OUTC | sed 's/-hl[[:space:]]*//g')
        # build HL/C
        if [ -f "$OUTC" ] && ${DoHLC}; then
          echo "building HL/C with $CC"
          $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
          -I$(realpath $(dirname $OUTC)) ${hashlink}/lib/*.hdll $OUTC \
          -lm -lhl -lSDL2 -lopenal -lGL
        fi
      '';

      # install with hl or with the c binary
      installPhase = ''
        mkdir -p $out/bin $out/lib
        # Hashlink bytecode
        if [ -f "$OUTHL" ]; then
        cp $OUTHL $out/lib/$(basename $OUTHL)
        echo "${hashlink}/bin/hl $out/lib/$(basename $OUTHL)" > $out/bin/${name};
        chmod +x $out/bin/${name};
        fi
        # native C
        if [ -f "$OUTC" ] && ${DoHLC}; then
        mkdir -p $out/bin
        cp ${name} $out/bin/${name}.bin
        fi
      '';
      meta = {
        license = pkgs.lib.licenses.free;
        platforms = pkgs.lib.platforms.all;
      } // (args.meta or { });
    });
}
