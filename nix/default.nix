# default.nix
# expose every function/derivations here
# also detect linux/MacOS and give the correct version
{ inputs, system }:
let
  # platform :
  isDarwin = inputs.nixpkgs.lib.strings.hasSuffix "darwin" system;

  # nixpkgs
  pkgs = import (if isDarwin then inputs.nixpkgs-darwin else inputs.nixpkgs) {
    inherit system;
  };

  # haxe language and compiler
  haxe = if isDarwin then
    (import darwin/haxe.nix { inherit (inputs) haxe nixpkgs-darwin; })
  else
    (import ./haxe.nix {
      inherit pkgs;
      inherit (inputs) haxe;
    });

  # a way to install haxelibs
  haxelib = import ./haxelib.nix { inherit pkgs; };

  # format library
  format = import ./format.nix {
    inherit pkgs;
    inherit (inputs) haxe_format;
  };

  # hashlink interpreter
  hashlink = if isDarwin then
    (import darwin/hashlink.nix { 
      inherit haxelib;
      inherit (inputs) hashlink nixpkgs-darwin;})
  else
    (import ./hashlink.nix {
      inherit pkgs haxelib;
      inherit (inputs) hashlink;
    });

  # Heaps game engine
  heaps = import ./heaps.nix {
    inherit pkgs haxelib;
    inherit (inputs) heaps;
    inherit (haxe) haxe_latest;
    inherit (format) format_latest;
    inherit (hashlink) hashlink_latest;
  };

in { inherit haxe hashlink heaps format; }
