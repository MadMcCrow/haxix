# dox.nix
# a haxe library for creating beautiful docs
{ pkgs, inputs, haxe, haxelib }:
haxelib.mkHaxelib {
    libname = "dox";
    src = inputs.dox;
    meta = {
      homepage = "https://github.com/HaxeFoundation/dox";
      description = "A Haxe tool to generate Haxe documentation";
      license = pkgs.lib.licenses.mit;
    };
}