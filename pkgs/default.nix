# flake part module for packages
args@{
  inputs,
  ...
}:
with builtins;
let
  # import the whole directory ( ignoring the default )
  packageFiles =
  filter (x: !(inputs.nixpkgs.lib.hasInfix "default.nix" x))
  (inputs.import-tree.leaves (./.));
in
{
  perSystem =
    {
      pkgs,
      lib,
      ...
    }:
    let
     # import all packages in a shared scope
      scope = lib.makeScope pkgs.newScope (self:
      listToAttrs (
        map ( path :
        lib.nameValuePair (lib.removeSuffix ".nix" (builtins.baseNameOf (toString path))) (self.callPackage path args))
        packageFiles
      ));

      packages =  lib.filterAttrs (
              _: v: lib.isDerivation v && lib.meta.availableOn pkgs.stdenv.hostPlatform v
            ) scope;
    in
    {
      # only expose packages supported on this platform
      inherit packages;

      # packages with libraries added
      legacyPackages = packages;

      # add an update script
      apps.update =
        with pkgs;
        with lib;
        let
          # update pinned sources
          script = writeShellScriptBin "update-pins" ''
            root=$(${getExe git} rev-parse --show-toplevel)
            ${getExe npins} -d "$root/packages/_npins" update
          '';
        in
        {
          type = "app";
          program = "${getExe script}";
        };
    };
}
