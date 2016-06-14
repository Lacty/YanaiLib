
#pragma once

#include <iostream>
#include "color.hpp"
#include "graphic.hpp"


struct GLFWwindow;

class App {
private:
  GLFWwindow* window_;

  Color clear_color_;

  int window_w_;
  int window_h_;

public:
  explicit App(int width, int height, const char* title);
  App(const App& src) = delete;
  ~App();
  
  bool isOpen();
  void letsStart();
  
  void begin();
  void end();
  
  void setClearColor(float r, float g, float b);
  void setClearColor(const Color& color);
};