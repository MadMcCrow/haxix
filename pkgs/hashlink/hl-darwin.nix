# darwin/hashlink-latest.nix
# hashlink-latest interpreter for haxe, on MacOS.
# only intel Mac supported, uses rosetta to run on M1
{
  inputs,
  version,
  haxe,
  darwin,
  libpng,
  ...
}:
let
  # we need objective-C
  objc = with darwin; [
    apple_sdk_11_0.objc4
    libobjc
  ];
  ObjCmakeFlags =
    let
      concatObjc = dir: builtins.concatStringsSep "," (map (x: "${x}/${dir}") objc);
    in
    [
      "CPATH=${concatObjc "include"}"
      "LIBRARY_PATH=${concatObjc "lib"}"
    ];
  # emulation for m1 macOS
  pkgs_eml = import inputs.nixpkgs { system = "x86_64-darwin"; };
in
# implementation :
pkgs_eml.hashlink.overrideAttrs (
  finalAttrs: previousAttrs: {
    inherit version;
    src = inputs.hashlink;
    buildInputs = previousAttrs.buildInputs ++ [ libpng ] ++ objc;
    makeFlags = previousAttrs.makeFlags ++ ObjCmakeFlags;
    postFixup =
      previousAttrs.postFixup
      + ''
        #   install_name_tool -add_rpath $out/lib $out/bin/hl
        # '';
    postInstall = ''
      ${haxe.installHaxelib {
        pname = "${finalAttrs.pname}";
        files = "other/haxelib/*";
        inherit version;
      }}
    '';
  }
)
