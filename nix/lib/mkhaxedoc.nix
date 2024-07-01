# mkHaxeDoc
# haxedoc : the resulting documentation of a haxe derivation :
# TODO: support for custom Compile.hxml  
{pkgs, stdenvNoCC, haxe, dox} : 
# function parameters :
{ haxeDrv, srcDir ? "src", main ? "Main", haxeLibs ? [ ] }:
stdenvNoCC.mkDerivation {
      # TODO : check/fix versionned names
      name = "${haxeDrv.name}-doc";
      src = haxeDrv.src;
      buildInputs = [ haxe dox ] ++ haxeDrv.buildInputs;
      unpackPhase = ''
        cp -R $src/src/* ./
      '';
      buildPhase = ''
        ls -la 
        ${haxe}/bin/haxe -xml docs/doc.xml -D doc-gen \
        ${builtins.concatStringsSep " " (map (x: "-lib ${x}") haxeLibs)}
        haxelib run dox -i docs
      '';
      installPhase = ''
        mkdir -p $out/doc
        cp pages/* $out/doc
      '';
      meta = haxeDrv.meta // {
        description = "Documentation of ${haxeDrv.name}";
      };
    };