# checks.nix
# some packages provided by this flake have checks
# this ensures that the flake works ! 
{
  stdenvNoCC,
  haxe,
  hashlink,
  heaps,
  ...
}:
{
  inherit hashlink;
  inherit haxe;
  inherit heaps;
}
