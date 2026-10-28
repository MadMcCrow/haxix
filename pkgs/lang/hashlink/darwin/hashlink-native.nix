# hashlink-native.nix
# native arm64 libhl + hdlls for HL/C on Apple Silicon (no JIT VM)
{ self, lib, pkgs, libpng, sdl3, ... }:
let
  pin = (import self + "/pkgs/_npins").hashlink;
in
pkgs.hashlink.overrideAttrs (previousAttrs: {
  pname = "hashlink-native";
  inherit (pin) version;
  src = pin;
  buildInputs = (builtins.filter (p: (p.pname or "") != "SDL2") previousAttrs.buildInputs) ++ [
    libpng
    sdl3
  ];
  # skip the `hl` executable, jit.c does not build on arm64
  buildPhase = ''
    runHook preBuild
    ninja libhl fmt.hdll openal.hdll sdl.hdll ui.hdll heaps.hdll
    runHook postBuild
  '';
  installPhase = ''
    runHook preInstall
    mkdir -p $out/lib $out/include
    cp -a bin/libhl*.dylib bin/*.hdll $out/lib/
    cp ../src/hl.h ../src/hlc.h ../src/hl_ffi.h ../src/hlc_main.c $out/include/ 2>/dev/null || true
    runHook postInstall
  '';
  postInstall = "";
  doInstallCheck = false;
  meta = previousAttrs.meta // {
    description = "native arm64 hashlink library, for HL/C";
    platforms = [ "aarch64-darwin" ];
  };
})
