
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  while(app.isOpen()) {
    app.letsStart();
    
    if (app.isPushKey(KEY_W)) {
      std::cout << "push w" << std::endl;
    }
    
    if (app.isPressKey(KEY_S)) {
      std::cout << "press s" << std::endl;
    }
    
    if (app.isPullKey(KEY_D)) {
      std::cout << "pull s" << std::endl;
    }
  }
  
  return 0;
}