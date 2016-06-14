
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  while(app.isOpen()) {
    app.letsStart();
    
    drawPoint(0, 0, 10, Color::red());
  }
  
  return 0;
}