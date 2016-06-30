
#include "lib/app.hpp"


int main() {
  int width  = 500;
  int height = 400;
  
  App app(width, height, "Title");
  app.setClearColor(Color::gray());
  
  while(app.isOpen()) {
    app.letsStart();

  }
  
  return 0;
}
