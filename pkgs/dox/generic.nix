{ version, inputs, lib, haxe, ... }:
haxe.buildHaxelib {
  libname = "dox";
  inherit version;
  src = inputs.dox;
  meta = {
    homepage = "https://github.com/HaxeFoundation/dox";
    description = "A Haxe tool to generate Haxe documentation";
    license = lib.licenses.mit;
  };
}
