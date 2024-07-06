{ callPackage, fetchFromGitHub, writeShellApplication, inputs, haxe, ...
}@args: rec {
  # haxelib :
  formatter = callPackage ./generic.nix (args // rec {
    version = "1.16.0";
    sha256 = "sha256-1m4jtZn38dJplH+qG2izirxkn4Cc9pAxv01lJZetd8I=";
  });

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
