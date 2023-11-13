class Main {
    static function main() {
      Rl.initWindow(1280, 720, "Hi");
      
      while(!Rl.windowShouldClose()) {
        Rl.beginDrawing();
        Rl.clearBackground(Rl.Colors.WHITE);
        Rl.endDrawing();
      }
      
      Rl.closeWindow();
    }
  }