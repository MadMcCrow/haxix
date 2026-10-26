# flake part module for templates
{ ... }:
  {
    flake.templates = rec {
      default = heaps; # we might not wanna be that opiniated
      heaps = {
        path = ./templates/heaps;
        description = "A simple haxe game with heaps";
        welcomeText = "";
      };
      lime = {
        path = ./templates/lime;
        description = "A simple haxe project with lime";
        welcomeText = "";
      };
    };
  }
