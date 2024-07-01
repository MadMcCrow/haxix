args : 
mkShell {
    buildInputs = [
      haxe
      hashlink
      format
      hxcpp
      heaps.heaps
      formatter.formatter
      formatter.haxefmt
      dox.dox
      raylib.raylib
      raylib.raylib-hx
    ] ++ (with pkgs; [ neko ]);
}