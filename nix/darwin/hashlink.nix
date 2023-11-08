# darwin/hashlink.nix
# Hashlink interpreter for haxe, on MacOS.
# only intel Mac supported, uses rosetta to run on M1
 pkgs :
let
  # we need objective-C
  objc = with pkgs.darwin; [ apple_sdk_11_0.objc4 libobjc ];
  # we support platform
  meta = pkgs.hashlink.meta // { platforms = pkgs.lib.platforms.darwin; };
  # make Flags to detect objective C
  ObjCmakeFlags = let
    concatObjc = dir:
      builtins.concatStringsSep "," (map (x: "${x}/${dir}") objc);
  in [ "CPATH=${concatObjc "include"}" "LIBRARY_PATH=${concatObjc "lib"}" ];

# implementation :
in (finalAttrs: previousAttrs:{
  inherit meta;
  buildInputs = (previousAttrs.buildInputs or []) ++ objc;
  makeFlags = (previousAttrs.makeFlags or []) ++ ObjCmakeFlags;
  postFixup = (previousAttrs.postFixup or "") + 
  ''
    install_name_tool -add_rpath $out/lib $out/bin/hl
  '';
})
