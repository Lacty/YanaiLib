
#include "lib/app.hpp"


struct Ball {
  float x;
  float y;
  float size;
  float vx;
  float vy;
  Color color;
};

int main() {
  int width  = 500;
  int height = 400;
  
  App app(width, height, "Title");
  app.setClearColor(Color::gray());
  
  Random random;
  
  std::vector<Ball> balls;
  
  while(app.isOpen()) {
    app.letsStart();
    
    if (app.isPushMouse(MOUSE_BUTTON_LEFT)) {
      // create ball
      balls.push_back({random.get(-width * 0.5f, width * 0.5f),
                       random.get(-height * 0.5f, height * 0.5f),
                       random.get(10.0f, 60.0f),
                       random.get(-5.0f, 5.0f),
                       random.get(-5.0f, 5.0f),
                       Color(random.get(0.0f, 1.0f),
                             random.get(0.0f, 1.0f),
                             random.get(0.0f, 1.0f))});
    }
    
    for (Ball& ball : balls) {
      drawPoint(ball.x, ball.y, ball.size, true, ball.color);
      ball.x += ball.vx;
      ball.y += ball.vy;
      
      if ((ball.x <= -width * 0.5) || (ball.x >= width * 0.5)) {
        ball.vx *= -1;
      }
      if ((ball.y <= -height * 0.5) || (ball.y >= height * 0.5)) {
        ball.vy *= -1;
      }
    }
  }
  
  return 0;
}