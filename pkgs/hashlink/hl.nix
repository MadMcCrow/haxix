# hashlink as a virtual machine
{
  version,
  inputs,
  hashlink,
  haxe,
  libpng,
  ...
}:
hashlink.overrideAttrs ( finalAttrs: previousAttrs: {
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
    doCheck = true;
    checkPhase = ''
        ls ${hashlink}/lib/haxe/hashlink
        ${hashlink}/bin/hl --version
    '';
  }
)
