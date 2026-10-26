{
  stdenvNoCC,
  version,
  inputs,
  lib,
  haxe,
  ...
}:
let
  sources = import ../_npins;
  pin = sources.dox;
  dox-unlib = haxe.buildHaxelib {
  pname = "dox";
  inherit (pin) version;
  src = pin;
  meta = {
    homepage = pin.url; # "https://github.com/HaxeFoundation/dox";
    description = "A Haxe tool to generate Haxe documentation";
    license = lib.licenses.mit;
  };
};
in
dox-unlib // (pkgs.callPackage (self + "/lib/haxedoc.nix") {dox = dox-unlib; inherit haxe;})
