
#include "lib/app.hpp"


int main() {
  int width  = 500;
  int height = 400;
  
  App app(width, height, "Title");
  app.setClearColor(Color::gray());
  
  Font font("../../../../res/rounded-l-mplus-1p-heavy.ttf");

  while(app.isOpen()) {
    app.letsStart();

    font.draw("hoge", 0, 0, 10);
  }
  
  return 0;
}
