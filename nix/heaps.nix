# heaps.nix
# Build heaps games with nix
pkgs :
with builtins;
let

  # shortcuts
  inherit (pkgs) stdenv;
  inherit (pkgs) lib;

  # custom haxe and hashlink
  haxenix = import ./haxe.nix pkgs;
  hl = haxenix.hashlink_latest;
  haxe = haxenix.haxe_latest;

  # the whole heaps.io engine
  heaps = [
    haxe
    hl
    pkgs.haxePackages.heaps
    pkgs.haxePackages.format
    pkgs.haxePackages.hlopenal
    pkgs.haxePackages.hlsdl  
  ];

  # compilation dependancies 
  buildPath= "build";
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
      # TODO : move to a separate command
      compileHxml = pkgs.writeText "compile.hxml" ''
        -cp src
        -lib heaps
        -lib hlsdl
        -lib hlopenal
        ${concatStringsSep "\n" (map (x: "-lib ${x}") libs)}
        -hl ${if release then "${buildPath}/${name}.c" else "${name}.hl"}
        -main ${main}
        ${if debug then "-debug" else "-dce full"}
      '';

      hlInstall = ''
        mkdir -p $out/bin $out/lib
        cp ${name}.hl $out/lib/${name}.hl
        echo "${hl}/bin/hl $out/lib/${name}.hl" > $out/bin/${name};
        chmod +x $out/bin/${name};
      '';

      cc = ''
      $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
      -I${buildPath} ${hl}/lib/*.hdll ${buildPath}/${name}.c \
      -lm -lhl -lSDL2 -lopenal -lGL
      '';

      cInstall = ''
        mkdir -p $out/bin
        cp ${name} $out/bin/
      '';

    in stdenv.mkDerivation {
      inherit name version src;
      buildInputs = deps ++ [hl];
      nativeBuildInputs = heaps ++ deps ++ nativeBuildInputs; # here BI is the one at the top of the file
      unpackPhase = ''
        cp -r $src/src ./
        ln -s ${compileHxml} ./compile.hxml
      '';

      buildPhase = concatStringsSep "\n" [
        "${haxe}/bin/haxe compile.hxml"
        (lib.strings.optionalString release cc)
      ];

      installPhase = (if release then cInstall else hlInstall);

    };
}
