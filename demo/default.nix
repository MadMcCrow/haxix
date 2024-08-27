{
  heaps,
  # raylib,
  lime,
  ...
}:
{
  # an example of a game
  heaps-demo = heaps.buildHeapsGame {
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

  lime-demo = lime.buildLimeGame {
    pname = "lime-helloworld";
    src = ./lime;
    version = "0.0.1-alpha";
    target = "html5";
  };
}
