{
  inputs,
  self,
  ...
}:
{
perSystem =
  {
    pkgs,
    lib,
    system,
    ...
  }:
let
  # expose our packages :
  haxe_pkgs = self.packages.${system};
  # an example of a game
  heaps-demo = haxe_pkgs.heaps.buildHeapsGame {
    name = "demo-heaps";
    src = ./heaps;
    version = "0.0.1-alpha";
    native = false;
  };

  # not working as-is
  # raylib-demo = raylib.mkGame {
  #    name = "heaps-helloworld";
  #    src = ./demo/raylib;
  #    version = "0.0.1-alpha";
  # };

  lime-demo = haxe_pkgs.lime.buildLimeGame {
    pname = "demo-lime";
    src = ./lime;
    version = "0.0.1-alpha";
    target = "html5";
  };

  demos = builtins.listToAttrs ( map (p:
    lib.nameValuePair (lib.getName p) p) [
     heaps-demo
    lime-demo
  ]);
in {
  # make demos runnable apps :
  apps = lib.mapAttrs ( _ : v:
    {
      type = "app";
      program = "${lib.getExe v}";
    }) demos;
  # make demos checks :
  checks = demos;
};
}
