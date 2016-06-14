
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  while(app.isOpen()) {
    app.letsStart();
    
    drawLine(-50, -50, 50, 50,
             5, Color::green());
  }
  
  return 0;
}