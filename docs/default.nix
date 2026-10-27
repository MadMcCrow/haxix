# flake part module for docs
{
  inputs,
  self,
  ...
}:
let
  mkDocs = { pkgs, pname, version, src,... } : pkgs.stdenvNoCC.mkDerivation {
    inherit pname version src;

    nativeBuildInputs = [ pkgs.mdbook ];

    buildPhase = ''
      mdbook build
    '';

    installPhase = ''
      cp -r book $out
    '';
  };
in
{
  perSystem =
    {
      pkgs,
      lib,
      system,
      ...
    }:
    {
      packages.haxix-docs = mkDocs {
        inherit pkgs;
        pname = "haxix-docs";
        version = "0.1";
        src = ./.;
      };
    };
}
