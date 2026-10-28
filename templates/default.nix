# flake part module for templates
{ ... }:
  {
    flake.templates = rec {
      default = heaps; # we might not wanna be that opiniated
      heaps = {
        path = ./heaps;
        description = "A simple haxe game with heaps";
        welcomeText = "";
      };
      lime = {
        path = ./lime;
        description = "A simple haxe project with lime";
        welcomeText = "";
      };
    };
  }
