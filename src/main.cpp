
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  Clock clock;
  
  // Clockを生成してからの時差を取得
  // 秒で取得される
  // sin conなどの関数に与える
  clock.time();
  
  // 前のフレームの時刻から現在時刻の時差を取得
  // フレーム落ちで処理内容が変更されては困る処理に使う
  // プレイヤーの移動など
  clock.dura();
  
  while(app.isOpen()) {
    app.letsStart();
    
  }
  
  return 0;
}