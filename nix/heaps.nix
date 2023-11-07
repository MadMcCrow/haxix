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
  heaps_engine = [
    haxe_latest
    format_latest
    heaps_latest
    hashlink_latest.hl
    hashlink_latest.hlsdl
    hashlink_latest.hlopenal
  ];

  # compilation dependancies
  buildPath = "build";
  buildLibs = heaps_engine;
  nativeBuildInputs = heaps_engine ++ buildLibs;

  # helper to make the compile command
  # TODO: expose and make generic
  mkCompileHxml =
    { sourceDir ? "src", libs, resources ? [ ], outpath, main, extra ? "" }:
    let
      concatPrefix = p: l:
        pkgs.lib.strings.concatLines (map (x: "${p} ${x}") l);
    in pkgs.writeText "compile.hxml" ''
      -cp src
      ${concatPrefix "-lib" libs}
       ${concatPrefix "-resource" (map (x: "${x.path}@${x.name}") resources)}
      -hl ${outpath}
      -main ${main}
      ${extra}
    '';

in {
  # the nix-shell for a heaps game
  mkShell = heapsGame:
    pkgs.mkShell {
      inherit nativeBuildInputs;
      buildInputs = nativeBuildInputs;
      inputsFrom = [ heapsGame ];
    };

  # The heaps game recipe
  # TODO : allow more custom options
  mkGame = { name, version, src, main ? "Main", deps ? [ ], libs ? [ ]
    , resources ? [ ], debug ? false, release ? false }:
    let

      # generate compile.hxml for heaps
      compileHxml = mkCompileHxml {
        inherit main resources;
        libs = [ "heaps" "hlsdl" "hlopenal" ] ++ libs;
        outpath =
          "${if release then "${buildPath}/${name}.c" else "${name}.hl"}";
        extra = "${if debug then "-debug" else "-dce full"}";
      };

      hlInstall = ''
        mkdir -p $out/bin $out/lib
        cp ${name}.hl $out/lib/${name}.hl
        echo "${hashlink_latest.hl}/bin/hl $out/lib/${name}.hl" > $out/bin/${name};
        chmod +x $out/bin/${name};
      '';

      cc = ''
        $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
        -I${buildPath} ${hashlink_latest.hl}/lib/*.hdll ${buildPath}/${name}.c \
        -lm -lhl -lSDL2 -lopenal -lGL
      '';

      cInstall = ''
        mkdir -p $out/bin
        cp ${name} $out/bin/
      '';
    in pkgs.stdenv.mkDerivation {
      inherit name version src;
      buildInputs = deps ++ heaps_engine;
      nativeBuildInputs = heaps_engine ++ deps ++ nativeBuildInputs;
      unpackPhase = ''
        cp -r $src/src ./
        ln -s ${compileHxml} ./compile.hxml
      '';

      buildPhase = builtins.concatStringsSep "\n" [
        "${haxe_latest}/bin/haxe compile.hxml"
        (pkgs.lib.strings.optionalString release cc)
      ];

      installPhase = if release then cInstall else hlInstall;
    };
}
