# treefmt.nix
# specify how to format the nonOS repository
# flake part module for apps
{
        # Used to find the project root
        projectRootFile = "flake.nix";

        programs = {
          autocorrect.enable = true;
          # all the nix formatter
          nixfmt.enable = true;
          statix.enable = true;
          deadnix = {
            enable = false;
            no-lambda-arg = false;
            no-lambda-pattern-names = true;
            no-underscore = true;
          };
          alejandra.enable = true;
          # shell formatter
          shellcheck.enable = true;

        };
      }
