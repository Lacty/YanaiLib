
#pragma once

#include <iostream>

// 直接触れないように隠します
namespace gl {
#include <GLFW/glfw3.h>
}

#include "color.hpp"

class App {
private:
  gl::GLFWwindow* window_;

  Color clear_color_;

  int window_w_;
  int window_h_;

public:
  explicit App(int width, int height, const char* title);
  App(const App& src) = delete;
  ~App();
  
  bool isOpen();
  void letsStart();
  
  void setClearColor(float r, float g, float b);
  void setClearColor(const Color& color);
};