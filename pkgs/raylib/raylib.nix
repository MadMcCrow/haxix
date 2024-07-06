# raylib/raylib.nix
# raylib source code for raylib-hx
{ raylib, inputs, ... }:
raylib.overrideAttrs (previousAttrs: {
  version = "5.0";
  src = inputs.raylib;
})
