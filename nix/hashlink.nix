# hashlink.nix
# Hashlink interpreter for haxe
{ pkgs, hashlink }:
let
  # install lib command
  withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];
  installLibHaxe = { libname, version, files ? "*" }: ''
    mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
    echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
    cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${
      withCommas version
    }/"
  '';

  # Custom HL with libraries for haxelib added
  # Support for Darwin added
  generic = { version, src }:
    pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      postInstall = (previousAttrs.postInstall or "") + ''
        ${installLibHaxe {
          libname = "${finalAttrs.pname}";
          files = "other/haxelib/*";
          inherit version;
        }}
        ${installLibHaxe {
          libname = "hlsdl";
          files = "libs/sdl/*";
          inherit version;
        }}
      '';
    });

in {
  # HASHLINK : flake latest version
  hashlink_latest = generic {
    src = hashlink;
    version = "latest";
  };
}
