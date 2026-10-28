# hashlink for MacOS: x86_64 build from the darwin branch, run through Rosetta on M1
{ inputs, ... }:
let
  # import x86_64-darwin packages
  pkgs_eml = import inputs.nixpkgs-darwin {
      system = "x86_64-darwin";
      config.allowDeprecatedx86_64Darwin = true; # silences the 26.05 warning
    };
    inherit (pkgs_eml) lib;
in
assert lib.assertMsg (lib.versionOlder lib.trivial.release "26.11")
  "hashlink JIT on darwin needs x86_64-darwin, which is dropped after 26.05";
pkgs_eml.hashlink.overrideAttrs (_finalAttrs: previousAttrs: {
  buildInputs =
    (builtins.filter (p: (p.pname or "") != "SDL2") previousAttrs.buildInputs)
    ++ [
      pkgs_eml.libpng
      pkgs_eml.apple-sdk_14
      pkgs_eml.sdl3
    ];

})
