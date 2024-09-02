# hxcpp/default.nix
# hxcpp is the cpp exporter for haxe 
{ callPackage, fetchFromGitHub, ... } @args :
{
  # let's use releases instead of fixed version from flake :
  hxcpp = callPackage ./generic.nix (args // rec {
    version = "4.3.55";
    src = fetchFromGitHub {
      owner = "HaxeFoundation";
      repo = "hxcpp";
      rev="v${version}";
      hash = "sha256-3y6IFT+tNWI9QkAslFGgSPV1F94nWB0E1YD+uNi5mU0=";
    };
  });
}
