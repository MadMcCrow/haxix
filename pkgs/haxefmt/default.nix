# haxefmt/default.nix
# haxefmt is a formatting tool to format haxe code
{
  lib,
  writeShellApplication,
  haxe,
  ...
}:
rec {
  # the library 
  formatter = haxe.buildHaxelib {
    pname = "formatter";
    version = "1.16.0";
    sha256 = "sha256-1m4jtZn38dJplH+qG2izirxkn4Cc9pAxv01lJZetd8I=";
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
      formatter
    ];
    text = ''
      if [ "$#" -gt 0 ]
      then haxelib run formatter -s "$\{@:1}"
      else echo "provide at least an argument"
      fi
    '';
  };
}
