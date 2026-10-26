

outputs = { self, nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      packages.${system}.docs = pkgs.stdenvNoCC.mkDerivation {
        pname = "project-docs";
        version = "1.0";
        src = self;

        nativeBuildInputs = [ pkgs.mdbook ];

        buildPhase = ''
          mdbook build
        '';

        installPhase = ''
          cp -r book $out
        '';
      };
    };
