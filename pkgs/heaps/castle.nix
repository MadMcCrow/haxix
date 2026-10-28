# Castle
# Datatable editor for Heaps
{ lib, stdenv, fetchFromGithub, neutralinojs, hxnodejs, haxe, ...} :
let
  pname = "castle";
  sources = import ../_npins;
  pin = sources.${pname};
in
stdenv.mkDerivation {
  inherit pname;
  inherit (pin) version;
  src = pin;
  buildInputs = [neutralinojs hxnodejs haxe];
  buildPhase = ''
    ${haxe}/bin/haxe castle.hxml
  '';
  meta = {
    description = "Castle DB is a structured static database for Heaps";
    license = lib.licenses.isc;
  };
}
