# heaps/lib.nix
# command to simplify building heaps games on nix
{ lib, stdenv, haxe, hashlink, heaps, ... }: {
  buildHeapsGame =
    { compileHxml ? "compile.hxml", ... }@args:
    let
      name = args.pname or args.name;
      # disable HL/C on MacOS M1
      DoHLC = if stdenv.isDarwin then "false" else "true";
    in stdenv.mkDerivation (args // {
      # build inputs
      buildInputs = (args.buildInputs or [ ]);
      nativeBuildInputs = (args.nativeBuildInputs or [ ]) ++ [haxe hashlink heaps];
      # copy source and the hxml
      unpackPhase = ''
        cp -r $src/* ./
      '';
      # build with haxe compiler
      buildPhase = ''
        ${haxe}/bin/haxe ${compileHxml}
        OUTHL=$(cat ${compileHxml} | grep '^-hl *[[:graph:]]*.hl' || true)
        OUTHL=$(echo $OUTHL | sed 's/-hl[[:space:]]*//g')
        ls -la ./build
        edefe
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
        # hl bytecode
        echo $OUTHL
        ls -la build
        defef
        if [ -f "$OUTHL" ]; then
        cp $OUTHL $out/lib/$(basename $OUTHL)
        echo "${hashlink}/bin/hl $out/lib/$(basename $OUTHL)" > $out/bin/${name};
        chmod +x $out/bin/${name};
        ls $out/bin -la
        efergdtg
        fi
        # native C
        if [ -f "$OUTC" ] && ${DoHLC}; then
        mkdir -p $out/bin
        cp ${name} $out/bin/${name}.bin
        fi
      '';
      meta = {
        license = lib.licenses.free;
        platforms = lib.platforms.all;
      } // (args.meta or { });
    });
}
