# haxe.nix
# build haxe from sources
{
  stdenv,
  lib,
  fetchurl,
  pkgs,
  ocaml-ng,
  zlib,
  pcre2,
  neko,
  mbedtls,
  darwin,
  callPackage,
  self,
  ...
}:
let
  # pinned sources
  sources = import ../_npins;
  pin = sources.haxe;


  # build without our nix helper
  # we need to specify pkgs instead of "haxe" directly to avoid infrec
  haxe-unlib = pkgs.haxe.overrideAttrs (previousAttrs: {
    inherit (pin) version ;
  src = pin;
  # add support for lib.getExe
  meta = previousAttrs.meta // {
    mainProgram = "haxe";
  };
});
in haxe-unlib //
  # add  the library to the package
  ( callPackage ( self + "/lib/haxelib.nix" ) { haxe = haxe-unlib; inherit self; } )
