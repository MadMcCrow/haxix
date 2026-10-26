# flake part module for packages
args@{
  inputs,
  self,
  ...
}:
{
  perSystem =
    {
      pkgs,
      lib,
      ...
    }:
    with lib;
    with builtins;
    {
      # only expose packages supported on this platform
      packages = filterAttrs (_: v: meta.availableOn pkgs.stdenv.hostPlatform v) (
        # import all packages in a shared scope
        pkgs.lib.makeScope pkgs.newScope (self:
        listToAttrs (
          map (
            x:
            let
              p = self.callPackage x args;
            in
            nameValuePair (getName p) p
          )
          # import the whole directory ( ignoring the default )
          (lib.traceVal
          (filter (x: !(lib.hasInfix "default.nix" x))
          (inputs.import-tree.leaves (./.))))
        ))
      );

      # add an update script
      apps.update =
        with pkgs;
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
