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
     # only expose packages supported on this platform
     # and that are actually derivations
     filterPkgs = list : filter (pkg : lib.meta.availableOn pkgs.stdenv.hostPlatform pkg) list;

     # import all packages in a shared scope
      scope = lib.makeScope pkgs.newScope (self:
      listToAttrs ( filterPkgs
        (map ( path :
        lib.nameValuePair (lib.removeSuffix ".nix" (builtins.baseNameOf (toString path))) (self.callPackage path args))
        packageFiles
      )));

      packages =  lib.filterAttrs (
              _: v: lib.isDerivation v
            ) scope;
    in
    {
      # new packages
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
            ${getExe npins} -d "$root/pkgs/_npins" update
          '';
        in
        {
          type = "app";
          program = "${getExe script}";
        };
    };
}
