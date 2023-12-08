# dox.nix
# a haxe library for creating beautiful docs
{
  pkgs,
  dox,
  haxe_latest,
  haxelib,
}: let
  # dox haxelib
  dox_latest = haxelib.mkHaxelib {
    version = "latest";
    libname = "dox";
    src = dox;
    meta = {
      description = "A Haxe tool to generate Haxe documentation";
      licenses = [pkgs.lib.licenses.mit];
    };
  };

  # haxedoc : the resulting documentation of a haxe derivation :
  # TODO: support for custom Compile.hxml
  mkHaxedoc = {
    haxeDrv,
    srcDir ? "src",
    main ? "Main",
    haxeLibs ? [],
  }:
    pkgs.stdenvNoCC.mkDerivation {
      # TODO : check/fix versionned names
      name = "${haxeDrv.name}-doc";
      src = haxeDrv.src;
      buildInputs = [haxe_latest dox_latest] ++ haxeDrv.buildInputs;
      unpackPhase = ''
        cp -R $src/src/* ./
      '';
      buildPhase = ''
        ls -la
        ${haxe_latest}/bin/haxe -xml docs/doc.xml -D doc-gen \
        ${builtins.concatStringsSep " " (map (x: "-lib ${x}") haxeLibs)}
        haxelib run dox -i docs
      '';
      installPhase = ''
        mkdir -p $out/doc
        cp pages/* $out/doc
      '';
      meta =
        haxeDrv.meta
        // {
          description = "Documentation of ${haxeDrv.name}";
        };
    };
in {
  inherit dox_latest mkHaxedoc;
}
