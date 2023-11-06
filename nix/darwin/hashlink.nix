# darwin/hashlink.nix
# hashlink for MacOS. only intel supported
{ nixpkgs-darwin, hashlink }:
let
  # MacOS requires some tweaking
  # hl is not available on M1
  pkgs = import nixpkgs-darwin { system = "x86_64-darwin"; };
  objc = with pkgs.darwin; [ apple_sdk_11_0.objc4 libobjc ];

  # install lib command
  installLibHaxe = { libname, version, files ? "*" }:
    let withCommas = pkgs.lib.replaceStrings [ "." ] [ "," ];
    in ''
      mkdir -p "$out/lib/haxe/${withCommas libname}/${withCommas version}"
      echo -n "${version}" > $out/lib/haxe/${withCommas libname}/.current
      cp -dpR ${files} "$out/lib/haxe/${withCommas libname}/${
        withCommas version
      }/"
    '';

  generic = { version, src }:
    pkgs.hashlink.overrideAttrs (finalAttrs: previousAttrs: {
      inherit version src;
      buildInputs = previousAttrs.buildInputs ++ objc;
      makeFlags = previousAttrs.makeFlags ++ [
        "CPATH=${builtins.concatStringsSep "," (map (x: "${x}/include") objc)}"
        "LIBRARY_PATH=${
          builtins.concatStringsSep "," (map (x: "${x}/lib") objc)
        }"
      ];
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
