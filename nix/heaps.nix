# heaps.nix
# Build heaps games with nix
{
  pkgs,
  heaps,
  haxe_latest,
  format_latest,
  haxelib,
  hashlink_latest,
}: let
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
    hashlink_latest
  ];

  # compilation dependancies
  buildPath = "build";
  buildLibs = with pkgs; [SDL2 openal];

  # helper to make the compile command
  # TODO: expose and make generic
  mkCompileHxml = {
    sourceDir ? "src",
    libs,
    resources ? [],
    outpath,
    main,
    extra ? "",
  }: let
    concatPrefix = p: l:
      pkgs.lib.strings.concatLines (map (x: "${p} ${x}") l);
  in
    pkgs.writeText "compile.hxml" ''
      -cp src
      ${concatPrefix "-lib" libs}
       ${concatPrefix "-resource" (map (x: "${x.path}@${x.name}") resources)}
      -hl ${outpath}
      -main ${main}
      ${extra}
    '';
in {
  inherit heaps_latest;

  # the nix-shell for a heaps game
  mkShell = heapsGame:
    pkgs.mkShell rec {
      nativeBuildInputs = buildLibs;
      buildInputs = heapsGame.buildInputs;
      inputsFrom = [heapsGame];
    };

  # The heaps game recipe
  # TODO : allow more custom options
  mkGame = {
    name,
    version,
    src,
    main ? "Main",
    haxelibs ? [], # haxe libraries
    resources ? [], # haxe compiled-in resources
    debug ? false, # have debug symbols
    native ? false, # compile to C (does not work with MacOS)
    nativeBuildInputs ? [],
    buildInputs ? [],
  } @ args
  : let
    # generate compile.hxml for heaps
    compileHxml = mkCompileHxml {
      inherit main resources;
      libs = ["heaps" "hlsdl" "hlopenal"] ++ haxelibs;
      outpath = "${
        if native
        then "${buildPath}/${name}.c"
        else "${name}.hl"
      }";
      extra = "${
        if debug
        then "-debug"
        else "-dce full"
      }";
    };
    # install with hl binary and game lib
    hlInstall = ''
      mkdir -p $out/bin $out/lib
      cp ${name}.hl $out/lib/${name}.hl
      echo "${hashlink_latest}/bin/hl $out/lib/${name}.hl" > $out/bin/${name};
      chmod +x $out/bin/${name};
    '';
    # there's no way to get hl hdll in arm64 for MacOS
    cc = ''
      $CC -O3 -o ${name} -fpie -flto -fuse-linker-plugin -std=c17 \
      -I${buildPath} ${hashlink_latest}/lib/*.hdll ${buildPath}/${name}.c \
      -lm -lhl -lSDL2 -lopenal -lGL
    '';
    cInstall = ''
      mkdir -p $out/bin
      cp ${name} $out/bin/
    '';
    # derivation
  in
    pkgs.stdenv.mkDerivation {
      inherit name version src;
      # build inputs
      buildInputs = buildInputs ++ heaps_engine;
      nativeBuildInputs = nativeBuildInputs ++ heaps_engine ++ buildLibs;
      # copy source and the hxml
      unpackPhase = ''
        cp -r $src/src ./
        ln -s ${compileHxml} ./compile.hxml
      '';
      # build with haxe compiler
      buildPhase = builtins.concatStringsSep "\n" [
        "${haxe_latest}/bin/haxe compile.hxml"
        (pkgs.lib.strings.optionalString native cc)
      ];
      # install with hl or with the c binary
      installPhase =
        if native
        then cInstall
        else hlInstall;
    };
}
