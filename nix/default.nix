# default.nix
# expose every function/derivations here
# also detect linux/MacOS and give the correct version
{
  inputs,
  system,
}:
with builtins; let
  inherit (inputs.nixpkgs.lib) platforms;

  systemSwitch = linux: darwin:
    if elem system platforms.darwin
    then darwin
    else if elem system platforms.linux
    then linux
    else throw "unsupported system";

  # nixpkgs : support MacOS
  nixpkgs = systemSwitch inputs.nixpkgs inputs.nixpkgs-darwin;
  pkgs = import nixpkgs {system = systemSwitch "x86_64-linux" "x86_64-darwin";};

  # haxe language and compiler
  # does not build in aaarch64-darwin
  haxe = import ./haxe.nix {
    inherit pkgs;
    inherit (inputs) haxe;
  };

  # a way to install haxelibs
  haxelib = import ./haxelib.nix {inherit pkgs;};

  # format library
  format = import ./format.nix {
    inherit pkgs;
    inherit (inputs) haxe_format;
  };

  # hashlink interpreter
  # does not build in aaarch64-darwin
  hashlink = import ./hashlink.nix {
    inherit pkgs;
    inherit haxelib;
    inherit (inputs) hashlink;
  };

  # Heaps game engine
  # does not build in aaarch64-darwin because of hashlink
  heaps = import ./heaps.nix {
    inherit pkgs haxelib;
    inherit (inputs) heaps;
    inherit (haxe) haxe_latest;
    inherit (format) format_latest;
    inherit (hashlink) hashlink_latest;
  };

  # Dox documentation tool
  dox = import ./dox.nix {
    inherit pkgs haxelib;
    inherit (inputs) dox;
    inherit (haxe) haxe_latest;
  };

  # lime
  lime = import ./lime.nix {
    inherit pkgs haxelib;
    inherit (format) format_latest;
    inherit (haxe) haxe_latest;
  };

  shell = pkgs.mkShell {
    buildInputs = [
      haxe.haxe_latest
      hashlink.hashlink_latest
      format.format_latest
      heaps.heaps_latest
      dox.dox_latest
      lime.lime_8_1_1
      pkgs.neko
    ];
  };
in {inherit haxe hashlink heaps format dox shell lime;}
