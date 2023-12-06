# lime.nix
{
  pkgs,
  haxelib,
  haxe_latest,
}: let
  lime_8_1_1 = haxelib.mkHaxelib {
    libname = "lime";
    version = "8.1.1";
    sha256 = "sha256-bOwe+jNymk+5liOv0eoFlNtrYxLBlxivntFnrQDDgKU=";
  };

  mkProjectXml = {
    name,
    version,
  }:
    pkgs.writeText "project.xml" ''
      <?xml version="1.0" encoding="utf-8"?>
      <project>
      	<meta title="${name}" package="${name}" version="${version}" company="none" />
      	<app main="Main" path="Export" file="${name}" />
      	<source path="src" />
      	<haxelib name="lime" />
      	<assets path="Assets" rename="assets" />
      </project>
    '';
in {
  inherit lime_8_1_1;
  # not really a 'game', but I'll stick with the convention
  mkGame = {
    name,
    version,
    src,
    target,
  }:
    pkgs.stdenv.mkDerivation {
      name = "${name}-${version}";
      inherit src;
      buildInputs = [lime_8_1_1 haxe_latest pkgs.neko];
      unpackPhase = ''
        cp -r $src/src ./
        ln -s ${mkProjectXml {inherit name version;}} ./project.xml
      '';
      buildPhase = ''
        ${haxe_latest}/bin/haxelib run lime build ${target}
      '';
      installPhase = ''
        mkdir -p $out/bin
        cp -r Export/${name} $out/bin/
      '';
    };
}
