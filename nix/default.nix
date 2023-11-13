# default.nix
# expose every function/derivations here
# also detect linux/MacOS and give the correct version
{ inputs, system }:
with builtins;
let
  inherit (inputs.nixpkgs.lib) platforms;

  systemSwitch = linux: darwin:
    if elem system platforms.darwin then
      darwin
    else if elem system platforms.linux then
      linux
    else
      throw "unsupported system";

  # nixpkgs : support MacOS
  nixpkgs = systemSwitch inputs.nixpkgs inputs.nixpkgs-darwin;
  pkgs =
    import nixpkgs { system = systemSwitch "x86_64-linux" "x86_64-darwin"; };

  # haxe language and compiler
  # does not build in aaarch64-darwin
  haxe = import ./haxe.nix {
    inherit pkgs;
    inherit (inputs) haxe;
  };

  # a way to install haxelibs
  haxelib = import ./haxelib.nix { inherit pkgs; };

  # format library
  format = import ./format.nix {
    inherit pkgs;
    inherit (inputs) haxe_format;
  };

  # hxcpp compiler support
  hxcpp = import ./hxcpp.nix {
    inherit pkgs;
    inherit (haxe) haxe_latest;
    inherit (inputs) hxcpp;
  };

  # hashlink interpreter
  # does not build in aaarch64-darwin
  hashlink = import ./hashlink.nix {
    inherit pkgs haxelib;
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

  # Formatter haxefmt
  formatter = import ./formatter.nix {
    inherit pkgs haxelib;
    inherit (inputs) formatter;
    inherit (haxe) haxe_latest;
  };

  # Dox documentation tool
  dox = import ./dox.nix {
    inherit pkgs haxelib;
    inherit (inputs) dox;
    inherit (haxe) haxe_latest;
  };

  # Raylib
  raylib = import ./raylib.nix {
    inherit pkgs haxelib;
    inherit (inputs) raylib-hx raylib;
    inherit (hxcpp) hxcpp_latest;
  };

  shell = pkgs.mkShell {
    buildInputs = [
      haxe.haxe_latest
      hashlink.hashlink_latest
      format.format_latest
      hxcpp.hxcpp_latest
      heaps.heaps_latest
      formatter.formatter_latest
      formatter.haxefmt
      dox.dox_latest
      raylib.raylibHaxe_latest
    ];
  };

in { inherit haxe hashlink haxelib hxcpp heaps format formatter dox raylib shell; }
