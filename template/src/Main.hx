// 
class Main extends hxd.App {
  override function init() {
    // TODO: write your game
    var tf = new h2d.Text(hxd.res.DefaultFont.get(), s2d);
    tf.text = "Hello World !";
  }
  static function main() {
      new Main();
  }
}