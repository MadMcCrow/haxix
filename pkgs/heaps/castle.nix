# Castle
# Datatable editor for Heaps
{ stdenv,fetchFromGithub, neutralino, hxnodejs, haxe, ...} :
let
  pname = "castle";
  sources = import ../_npins;
  pin = sources.${pname};
in
stdenv.mkDerivation {
  inherit pname;
  inherit (pin) version;
  src = pin;
  buildInputs = [neutralino hxnodejs haxe];
  buildPhase = ''
    ${haxe}/bin/haxe castle.hxml
  '';
}
