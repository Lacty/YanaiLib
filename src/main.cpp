
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  while(app.isOpen()) {
    app.letsStart();
    
    drawFillRect(0, 0, 100, 300, Color::blue());
  }
  
  return 0;
}