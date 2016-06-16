
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  Font font("../../../res/rounded-l-mplus-1p-heavy.ttf");
  
  while(app.isOpen()) {
    app.letsStart();
    
    font.draw(L"Yanai もくもく会きてね!", 0, 0, 40);
  }
  
  return 0;
}