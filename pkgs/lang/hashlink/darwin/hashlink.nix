# hashlink for MacOS: x86_64 build from the darwin branch, run through Rosetta on M1
args@{ self, inputs, ... }:
let
  # import x86_64-darwin packages
  pkgs_eml = import inputs.nixpkgs-darwin {
      system = "x86_64-darwin";
      config.allowDeprecatedx86_64Darwin = true; # silences the 26.05 warning
    };
    inherit (pkgs_eml) lib callPackage;

    baseHashlink = callPackage ../hashlink.nix args;

    # get latest sources :
    pin = (import self + "/pkgs/_npins").hashlink;
in
# we still need to assert if things get updated and the build breaks
assert lib.assertMsg (lib.versionOlder lib.trivial.release "26.11")
  "hashlink JIT on darwin needs x86_64-darwin, which is dropped after 26.05";
# build the x86_64 package
pkgs_eml.hashlink.overrideAttrs (_finalAttrs: previousAttrs: {
  buildInputs =
    (builtins.filter (p: (p.pname or "") != "SDL2") previousAttrs.buildInputs)
    ++ [
      pkgs_eml.libpng
      pkgs_eml.apple-sdk_14
      pkgs_eml.sdl3
    ];
    # copy postInstall from the linux version
    postInstall = (previousAttrs.postInstall or "") + baseHashlink.postInstall;
    # check that JIT is working
    doInstallCheck = true;
    installCheckPhase = (previousAttrs.installCheckPhase or "") + baseHashlink.installCheckPhase;

      # support the macOS platform
      meta = previousAttrs.meta // {
         platforms = lib.platforms.darwin ++ [pkgs_eml.stdenv.hostPlatform.system];
       };
})
