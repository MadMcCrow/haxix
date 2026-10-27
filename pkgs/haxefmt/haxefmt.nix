# haxefmt/default.nix
# haxefmt is a formatting tool to format haxe code
{
  lib,
  writeShellApplication,
  haxe,
  ...
}:
let
  pname = "formatter";
  sources = import ../_npins;
  pin = sources.${pname};
in
rec {
  # the library
  haxe-formatter = haxe.buildHaxelib {
    pname = lib.toLower pname;
    inherit (pin) version;
    src = pin;

    meta = {
      homepage = "https://github.com/HaxeCheckstyle/haxe-formatter";
      description = "A Haxe tool to format haxe code";
      license = lib.licenses.mit;
    };
  };

  # command to run in a shell-env
  haxefmt = writeShellApplication {
    name = "haxefmt";
    runtimeInputs = [
      haxe
      haxe-formatter
    ];
    text = ''
      if [ "$#" -gt 0 ]
      then haxelib run formatter -s "$\{@:1}"
      else echo "provide at least an argument"
      fi
    '';
  };
}
