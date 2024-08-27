# lime/lib.nix
# function provided to work with lime 
{
  stdenv,
  writeText,
  neko,
  lime,
  haxe,
  format,
  hxp,
  ...
}:
rec {
  mkProjectXml =
    name: version:
    writeText "project.xml" ''
      <?xml version="1.0" encoding="utf-8"?>
      <project>
      	<meta title="${name}" package="${name}" version="${version}" company="none" />
      	<app main="Main" path="export" file="${name}" />
      	<source path="src" />
      	<haxelib name="lime" />
      	<assets path="Assets" rename="assets" />
      </project>
    '';

  # Not a Game per-se. 
  # maybe rename it buildLimeApplication or buildLimePackage
  buildLimeGame =
    {
      src,
      target,
      version,
      ...
    }@attrs:
    stdenv.mkDerivation rec {
      # derivation name
      name = attrs.name or "${attrs.pname}-${attrs.version}";
      inherit src version;

      buildInputs = [
        lime
        haxe
        neko
        format
        hxp
      ];

      unpackPhase = ''
        export HOME=$(mktemp -d)
        cp -r $src/src ./
        cp -r $src/Assets ./
        ln -s ${mkProjectXml name version} ./project.xml
      '';

      buildPhase = ''
        mkdir export
        ${haxe}/bin/haxelib run lime build ${target} -eval
      '';

      installPhase = ''
        mkdir -p $out/bin
        cp -r export/${target}/bin/* $out/bin/
      '';
    };

}
