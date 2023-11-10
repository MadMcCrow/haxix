# heaps.nix
# Build heaps games with nix 
{ pkgs, heaps, haxe_latest, format_latest, haxelib, hashlink_latest }:
let
  # TODO : make generic version
  heaps_latest = haxelib.mkHaxelib {
    version = "latest";
    libname = "heaps";
    src = heaps;
    meta = pkgs.haxePackages.heaps.meta;
  };

  # the whole heaps.io engine
  dependancies = [
    haxe_latest
    format_latest
    heaps_latest
    hashlink_latest
    pkgs.SDL2
    pkgs.openal
  ];

in {
  inherit heaps_latest;

  # The heaps game recipe
  # TODO : Disable C compilation on MacOS
  mkGame = {
  compileHxml ? "compile.hxml"
  , ...
  } @args
  :
  let 
  name = args.pname or args.name;
  in
  pkgs.stdenv.mkDerivation (args //{
    # build inputs
    buildInputs = (args.buildInputs or []) 
    ++ dependancies;
    nativeBuildInputs = (args.nativeBuildInputs or [])
    ++ dependancies;
    # copy source and the hxml
    unpackPhase = ''
      cp -r $src/* ./
    '';
    # build with haxe compiler
    buildPhase = ''
      ${haxe_latest}/bin/haxe ${compileHxml}
      OUTHL=$(cat ${compileHxml} | grep '^-hl *[[:graph:]]*.hl' || true)
      OUTHL=$(echo $OUTHL | sed 's/-hl[[:space:]]*//g')
      OUTC=$(cat ${compileHxml} | grep '^-hl *[[:graph:]]*.c' || true)
      OUTC=$(echo $OUTC | sed 's/-hl[[:space:]]*//g')
      # build HL/C
      if [ -f "$OUTC" ]; then
        echo "building HL/C with $CC"
        $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
        -I$(realpath $(dirname $OUTC)) ${hashlink_latest}/lib/*.hdll $OUTC \
        -lm -lhl -lSDL2 -lopenal -lGL
      fi
    '';

    # install with hl or with the c binary
    installPhase =  ''
      mkdir -p $out/bin $out/lib
      # Hashlink bytecode
      if [ -f "$OUTHL" ]; then
      cp $OUTHL $out/lib/$(basename $OUTHL)
      echo "${hashlink_latest}/bin/hl $out/lib/$(basename $OUTHL)" > $out/bin/${name};
      chmod +x $out/bin/${name};
      fi
      # native C
      if [ -f "$OUTC" ]; then
      mkdir -p $out/bin
      cp ${name} $out/bin/${name}.bin
      fi
    '';
    meta = {
        license = pkgs.lib.licenses.free;
        platforms = pkgs.lib.platforms.all;
    } // (args.meta or {});
  });
}