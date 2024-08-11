{
  version,
  inputs,
  hashlink,
  haxe,
  libpng,
  ...
}:
hashlink.overrideAttrs (
  finalAttrs: previousAttrs: {
    inherit version;
    src = inputs.hashlink;
    buildInputs = previousAttrs.buildInputs ++ [ libpng ];
    postInstall = ''
      ${haxe.installHaxelib {
        pname = "${finalAttrs.pname}";
        files = "other/haxelib/*";
        inherit version;
      }}
    '';
  }
)
