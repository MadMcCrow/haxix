# heaps.nix
# Build heaps games with nix
{ pkgs, inputs, ... }@args:
let
  haxelib = import ./haxe.nix args;

  heaps_latest = haxelib.buildHaxeLib {
    version = "latest";
    libname = "heaps";
    src = inputs.heaps;
    meta = pkgs.haxePackages.heaps.meta;
  };

  # the whole heaps.io engine
  heaps = [
    haxelib.haxe_latest
    haxelib.hashlink_latest
    haxelib.format_latest
    heaps_latest
    pkgs.haxePackages.hlopenal
  ];

  # compilation dependancies
  buildPath = "build";
  buildLibs = (with pkgs; [ glibc SDL SDL2 openal ]) ++ heaps;
  nativeBuildInputs = heaps ++ buildLibs;
in {
  # the nix-shell for a heaps game
  mkShell = heapsGame:
    pkgs.mkShell {
      inherit nativeBuildInputs;
      packages = nativeBuildInputs;
      inputsFrom = [ heapsGame ];
    };

  # The heaps game recipe
  buildGame = { name, version, src, main ? "Main", deps ? [ ], libs ? [ ]
    , useInterpreter ? true, debug ? false, release ? false }:
    let
      # the compile command
      # TODO : 
      # - move to a separate command
      # - allow for custom options for users
      compileHxml = pkgs.writeText "compile.hxml" ''
        -cp src
        -lib heaps
        -lib hlsdl
        -lib hlopenal
        ${builtins.concatStringsSep "\n" (map (x: "-lib ${x}") libs)}
        -hl ${if release then "${buildPath}/${name}.c" else "${name}.hl"}
        -main ${main}
        ${if debug then "-debug" else "-dce full"}
      '';

      hlInstall = ''
        mkdir -p $out/bin $out/lib
        cp ${name}.hl $out/lib/${name}.hl
        echo "${haxelib.hashlink_latest}/bin/hl $out/lib/${name}.hl" > $out/bin/${name};
        chmod +x $out/bin/${name};
      '';

      cc = ''
        $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
        -I${buildPath} ${haxelib.hashlink_latest}/lib/*.hdll ${buildPath}/${name}.c \
        -lm -lhl -lSDL2 -lopenal -lGL
      '';

      cInstall = ''
        mkdir -p $out/bin
        cp ${name} $out/bin/
      '';
    in pkgs.stdenv.mkDerivation {
      inherit name version src;
      buildInputs = deps ++ [ haxelib.hashlink_latest ];
      nativeBuildInputs = heaps ++ deps
        ++ nativeBuildInputs; # here BI is the one at the top of the file
      unpackPhase = ''
        cp -r $src/src ./
        ln -s ${compileHxml} ./compile.hxml
      '';

      buildPhase = builtins.concatStringsSep "\n" [
        "${haxelib.haxe_latest}/bin/haxe compile.hxml"
        (pkgs.lib.strings.optionalString release cc)
      ];

      installPhase = if release then cInstall else hlInstall;
    };
}
