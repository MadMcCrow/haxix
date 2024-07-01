 # an example of a game
      heaps-demo = system:
        (haxix system).heaps.mkGame {
          name = "heaps-helloworld";
          src = ./demo/heaps;
          version = "0.0.1-alpha";
          native = false;
        };

      raylib-demo = system:
        (haxix system).raylib.mkGame {
          name = "heaps-helloworld";
          src = ./demo/heaps;
          version = "0.0.1-alpha";
          native = false;
        };