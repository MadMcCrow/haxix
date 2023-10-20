# heaps.nix
# Build heaps games with nix
pkgs:
with builtins; let
  # shortcuts
  inherit (pkgs) stdenv;
  inherit (pkgs) lib;

  # custom haxe and hashlink
  haxenix = import ./haxe.nix pkgs;
  hl = haxenix.hashlink_latest;
  haxe = haxenix.haxe_latest;

  withCommas = lib.replaceStrings ["."] [","];

  installLibHaxe = {
    libname,
    version,
    files ? "*",
  }: ''
    mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
    echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
    cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${withCommas version}/"
  '';

  heaps_latest = stdenv.mkDerivation {
    name = "heaps";
    src = pkgs.fetchFromGitHub {
      owner = "HeapsIO";
      repo = "heaps";
      rev = "c83ba0299da99f93e2d64bfdaf3acfca66698f9c";
      sha256 = "sha256-hsuNaXLc1HBAT3u7ipQrdPagdGoq7QznZ90e0eLh0pk=";
    };
    installPhase = installLibHaxe {
      libname = "heaps";
      version = "alpha";
    };
    meta = {
      homepage = "http://heaps.io";
      license = lib.licenses.mit;
      platforms = lib.platforms.all;
      description = "Heaps : Haxe Game Framework";
    };
  };

  format_latest = stdenv.mkDerivation {
    name = "format";
    src = pkgs.fetchFromGitHub {
      owner = "HaxeFoundation";
      repo = "format";
      rev = "39787764801f9e02c5b5ed771490e767a5488e65";
      sha256 = "sha256-i8ZpU0/j9v505QagjBAMva202rkY5+QVex2paw2gRWk=";
    };
    installPhase = installLibHaxe {
      libname = "format";
      version = "alpha";
    };
    meta = {
      homepage = "https://haxe.org";
      license = lib.licenses.mit;
      platforms = lib.platforms.all;
      description = "Various files formats support for Haxe ";
    };
  };

  # the whole heaps.io engine
  heaps = [
    haxe
    hl
    heaps_latest
    format_latest
    # pkgs.haxePackages.hlsdl
    # pkgs.haxePackages.format
    pkgs.haxePackages.hlopenal
  ];

  # compilation dependancies
  buildPath = "build";
  buildLibs = (with pkgs; [glibc SDL SDL2 openal]) ++ heaps;
  nativeBuildInputs = heaps ++ buildLibs;
in {
  # the nix-shell for a heaps game
  mkShell = heapsGame:
    pkgs.mkShell {
      inherit nativeBuildInputs;
      packages = nativeBuildInputs;
      inputsFrom = [heapsGame];
    };

  # The heaps game recipe
  buildGame = {
    name,
    version,
    src,
    main ? "Main",
    deps ? [],
    libs ? [],
    useInterpreter ? true,
    debug ? false,
    release ? false,
  }: let
    # the compile command
    # TODO : move to a separate command
    compileHxml = pkgs.writeText "compile.hxml" ''
      -cp src
      -lib heaps
      -lib hlsdl
      -lib hlopenal
      ${concatStringsSep "\n" (map (x: "-lib ${x}") libs)}
      -hl ${
        if release
        then "${buildPath}/${name}.c"
        else "${name}.hl"
      }
      -main ${main}
      ${
        if debug
        then "-debug"
        else "-dce full"
      }
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
  in
    stdenv.mkDerivation {
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

      installPhase =
        if release
        then cInstall
        else hlInstall;
    };
}
