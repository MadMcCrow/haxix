# haxefmt/formatter.nix
# haxefmt is a formatting tool to format haxe code
# the command
{
  lib,
  writeShellApplication,
  haxe,
  formatter,
  ...
}:
  # command to run in a shell-env
  writeShellApplication {
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
    meta = {
      description = "format haxe code with haxe-formatter";
      inherit (formatter.meta) license;
    };
  }
