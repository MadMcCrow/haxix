{ callPackage, writeShellApplication, inputs, haxe, ... }: rec {
  formatter = callPackage ./generic.nix {
    inherit haxe;
    src = inputs.formatter;
    version = "1.15.0";
  };
  # command to run in a shell-env
  haxefmt = writeShellApplication {
    name = "haxefmt";
    runtimeInputs = [ haxe formatter ];
    text = ''
      if [ "$#" -gt 0 ]
      then haxelib run formatter -s "$\{@:1}"
      else echo "provide at least an argument"
      fi
    '';
  };
}
