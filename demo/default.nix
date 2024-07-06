{ heaps, raylib, ... }: {
  # an example of a game
  heaps-demo = heaps.buildHeapsGame {
    name = "heaps-helloworld";
    src = ./heaps;
    version = "0.0.1-alpha";
    native = false;
  };

  # raylib-demo = raylib.mkGame {
  #   name = "heaps-helloworld";
  #   src = ./demo/heaps;
  #   version = "0.0.1-alpha";
  #   native = false;
  # };
}
