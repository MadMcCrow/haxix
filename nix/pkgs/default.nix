{ callPackage, lib, inputs, system, ... } @args :
let 
pkgs = if builtins.elem system inputs.nixpkgs.lib.platforms.darwin then
  import inputs.nixpkgs-darwin { system = "x86_64-darwin"; }
else if builtins.elem system inputs.nixpkgs.lib.platforms.linux then
  import inputs.nixpkgs { system = "x86_64-linux"; }
else
  throw "unsupported system";
in
(builtins.foldl' (x: y: lib.recursiveUpdate x y) { } 
(x : callPackage x args) [./shared])
  