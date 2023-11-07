# default.nix
# expose every function/derivations here
# also detect linux/MacOS and give the correct version
{ inputs, system }:
with builtins;
let
  # support for MacOS M1
  inherit (inputs.nixpkgs.lib) platforms;
  isDarwin = elem system platforms.darwin;
  isLinux = elem system platforms.linux;

  # switch between systems
  systemSwitch = linux: darwin:
    if isDarwin then
      darwin
    else if isLinux then
      linux
    else
      throw "unsupported system";

  # nixpkgs
  systemx86 = systemSwitch "x86_64-linux" "x86_64-darwin";
  nixpkgs = systemSwitch inputs.nixpkgs inputs.nixpkgs-darwin;
  pkgs = import nixpkgs { inherit system; };
  x86pkgs = import nixpkgs { system = systemx86; };

  # haxe language and compiler
  haxe = import ./haxe.nix {
    inherit (inputs) haxe;
    pkgs = systemSwitch pkgs x86pkgs;
  };

  # a way to install haxelibs
  haxelib = import ./haxelib.nix { inherit pkgs; };

  # format library
  format = import ./format.nix {
    inherit pkgs;
    inherit (inputs) haxe_format;
  };

  # hashlink interpreter
  hashlink = import (systemSwitch ./hashlink.nix ./darwin/hashlink.nix) {
    pkgs = systemSwitch pkgs x86pkgs;
    inherit haxelib;
    inherit (inputs) hashlink;
  };

  # Heaps game engine
  heaps = import ./heaps.nix {
    inherit pkgs haxelib;
    inherit (inputs) heaps;
    inherit (haxe) haxe_latest;
    inherit (format) format_latest;
    inherit (hashlink) hashlink_latest;
  };

in { inherit haxe hashlink heaps format; }
