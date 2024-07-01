# default.nix
args :
rec {
  # import each folder accordingly :
  packages = import ./pkgs (args // haxelib);
  haxelib = import ./lib  (args // packages);
  shell = import ./shell (args // packages // haxelib);
}