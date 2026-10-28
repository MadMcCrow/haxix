# shell.nix
# give the default dev-shell for systems without flakes
{
  pkgs ? import <nixpkgs> { },
}:
let
  lockFile = builtins.fromJSON (builtins.readFile ./flake.lock);
  flake-compat-node = lockFile.nodes.${lockFile.nodes.root.inputs.flake-compat};
  flake-compat = builtins.fetchTarball {
    inherit (flake-compat-node.locked) url;
    sha256 = flake-compat-node.locked.narHash;
  };

  flake = import flake-compat {
    src = ./.;
  };
in
# expose default shell
flake.outputs.devShells.${pkgs.stdenv.hostPlatform.system}.default
