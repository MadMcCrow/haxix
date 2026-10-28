# neutralino.nix
# neutralino is a lighter nwjs
{buildNpmPackage, fetchzip,  lib, ...} :
let
  pname = "neutralinojs";
  sources = import ../_npins;
  pin = sources.${pname};
in
buildNpmPackage rec {
  inherit pname;
  inherit (pin) version;
  src = pin;

  npmDepsHash = "";

  #npmBuildScript = "production";

  meta = with lib; {
    description = "Lightweight and portable desktop application development framework";
    homepage = "https://github.com/neutralinojs/neutralinojs";
    license = licenses.mit;
  };
}
