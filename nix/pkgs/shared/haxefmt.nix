{ pkgs, inputs, haxelib, haxe }:
let
  generic_lib = { src, version }:
    haxelib.mkHaxelib {
      inherit src version;
      libname = "haxe-formatter";
      meta = {
        homepage = "https://github.com/HaxeCheckstyle/haxe-formatter";
        description = "A Haxe tool to format haxe code";
        license = pkgs.lib.licenses.mit;
      };
    };
  # command to run in a shell-env
  # TODO : build real formatter, instead of using just src
  generic_command = { src, version }@args:
    pkgs.writeShellApplication {
      name = "haxefmt";
      runtimeInputs = [ haxe (generic_lib args) ];
      text = ''
        haxelib run formatter -s "$1"
      '';
    };
in {
  # lib
  formatter = generic_lib {
    src = inputs.formatter;
    version = "1.15.0";
  };
  # quick command
  haxefmt = generic_command {
    src = inputs.formatter;
    version = "1.15.0";
  };
}
