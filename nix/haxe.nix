# haxe.nix
# a collection of functions and derivation to have custom haxe support
pkgs :
let
  # shortcuts
  inherit (pkgs) stdenv;
  inherit (pkgs) lib;

  withCommas = lib.replaceStrings [ "." ] [ "," ];

  # install lib command
  installLibHaxe = { libname, version, files ? "*" }: ''
    mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
    echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
    cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${withCommas version}/"
  '';

  # Custom HL with libraries for haxelib added
  my_hashlink = {version, sha256,...}@args : pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
    inherit version;
    postInstall = (previousAttrs.postInstall or "") + ''
      ${installLibHaxe { libname = "${finalAttrs.pname}"; files ="other/haxelib/*"; inherit version; }}
    '';

    src = pkgs.fetchFromGitHub {
    owner = "HaxeFoundation";
    repo = "hashlink";
    rev = version;
    inherit sha256;
  };
  });

  # Custom haxe version :
  # haxe 4.3.2 : sha256-wSSX9d/WBzylQ+XYhjM/qpdAXtMNDoQUIWRPL/2AnMo= -> not compiling
  # haxe 4.3.0 : sha256-uLvtrreMK5OaLk2aLGcdqX9yaRU8qAI6SWQl7yGpLz0= -> not compiling
  # haxe 4.2.5 : sha256-Y0gx6uOQX4OZgg8nK4GJxRR1rKh0S2JUjZQFVQ4cfTs= -> works
  my_haxe = {version, sha256, ocaml-ng, ... } @args : pkgs.haxe.overrideAttrs (finalAttrs: previousAttrs: rec {
    inherit version;
    src = pkgs.fetchFromGitHub {
      rev = version;
      inherit sha256;
      owner = "HaxeFoundation";
      repo = "haxe";
      fetchSubmodules = true;
    };
    buildInputs = let 
    # newer ocaml
      ocamlDependencies = with ocaml-ng; [
        ocaml
        findlib
        sedlex
        xml-light
        ptmap
        camlp5
        sha
        dune_3
        luv
        extlib
        stdlib-shims
      ];
    in
    (with pkgs; [ zlib pcre neko mbedtls_2 ]) ++ ocamlDependencies ++
    (lib.optional (stdenv.isDarwin) pkgs.darwin.apple_sdk.frameworks.Security) ;
  });


in
{
  # haxe with version newer than the one in nixpkgs
  haxe_latest = my_haxe {  
    version = "4.2.5";
    sha256 = "sha256-Y0gx6uOQX4OZgg8nK4GJxRR1rKh0S2JUjZQFVQ4cfTs=";
    ocaml-ng = pkgs.ocaml-ng.ocamlPackages_4_14;
  };

  # this is not realy latest, but still
  hashlink_latest = my_hashlink {
    version = "1.13";
    sha256 = "lpHW0JWxbLtOBns3By56ZBn47CZsDzwOFBuW9MlERrE=";
  };

  # helper to build libraries
  # this is a copy of what nixpkgs does, because it is not exposed to uss
  buildHaxeLib = { libname, version, sha256 ? "", meta, ... }@attrs:
    stdenv.mkDerivation (attrs // {
      name = attrs.name or "${libname}-${version}";

      buildInputs = (attrs.buildInputs or [ ])
        ++ (with pkgs; [ haxe neko ]); # for setup-hook.sh to work
      src = attrs.src or (pkgs.fetchzip rec {
        name = "${libname}-${version}";
        url = "http://lib.haxe.org/files/3.0/${withCommas name}.zip";
        inherit sha256;
        stripRoot = false;
      });

      installPhase = attrs.installPhase or ''
        runHook preInstall
        (
          if [ $(ls $src | wc -l) == 1 ]; then
            cd $src/* || cd $src
          else
            cd $src
          fi
          ${installLibHaxe { inherit libname version; }}
        )
        runHook postInstall
      '';

      meta = {
        homepage = "http://lib.haxe.org/p/${libname}";
        license = lib.licenses.bsd2;
        platforms = lib.platforms.all;
        description = throw "please write meta.description";
      } // attrs.meta;
    });
}