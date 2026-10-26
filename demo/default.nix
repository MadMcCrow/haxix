{
  heaps,
  # raylib,
  lime,
  ...
}:
{
perSystem =
  {
    pkgs,
    lib,
    ...
  }:
let
  # expose our packages :
  haxe_pkgs = self.packages.${system};
  # an example of a game
  heaps-demo = haxe_pkgs.heaps.buildHeapsGame {
    name = "heaps-helloworld";
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
    pname = "lime-helloworld";
    src = ./lime;
    version = "0.0.1-alpha";
    target = "html5";
  };

  demos = [
     heaps-demo
    lime-demo
  ];
in {
  # make demos runnable apps :
  apps = builtins.listToAttrs ( map (p:
    nameValuePair (getName p)
    {
      type = "app";
      program = "${getExe p}";
    }) demos);
  # make demos checks :
  checks = builtins.listToAttrs ( map (p:
    nameValuePair (getName p) p) demos);
};
}
