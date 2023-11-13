{ pkgs, haxelib, formatter, haxe_latest }:
let
  generic_lib = { src, version }:
    haxelib.mkHaxelib {
      inherit src version;
      libname = "formatter";
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
      runtimeInputs = [ haxe_latest (generic_lib args) ];
      text = ''
        haxelib run formatter -s "$1"
      '';
    };
in {
  # lib
  formatter_latest = generic_lib {
    src = formatter;
    version = "latest";
  };
  # quick command
  haxefmt = generic_command {
    src = formatter;
    version = "latest";
  };
}
