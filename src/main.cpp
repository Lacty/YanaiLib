
#include "lib/app.hpp"


int main() {
  App app(500, 400, "Test");
  
  app.setClearColor(Color::gray());
  
  Random random;
  
  for (int i = 0; i < 10; i++) {
    std::cout << random.get(0.0, 1.0) << std::endl;
  }
  
  while(app.isOpen()) {
    app.letsStart();
    
  }
  
  return 0;
}