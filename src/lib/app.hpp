
#pragma once

#include <iostream>
#include <Eigen/Core>
#include "color.hpp"
#include "graphic.hpp"
#include "key.hpp"
#include "mouse.hpp"
#include "font.hpp"
#include "random.hpp"
#include "clock.hpp"


struct GLFWwindow;

class App {
private:
  GLFWwindow* window_;

  // $BGX7J?'(B
  Color clear_color_;

  // window$B$N%5%$%:(B
  int window_w_;
  int window_h_;
  
  Key key_;
  Mouse mouse_;
  
  // CallBack$B4X?t(B
  static void mouseButtomCallback(GLFWwindow* window, int button, int action, int mods);
  static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
  static void windowSizeCallBack(GLFWwindow* window, int width, int height);
  static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
  
  void setCallBackFunc();
  
  // $BJL:BI87O(B($B:8>e86E@(B)$B$J$N$G1#$7$F$*$/(B
  void setMousePos(const Vec2d& pos);
  
  // $BIA2h<B9T(B
  void begin();
  
  // $BIA2h=*N;(B
  void end();

public:
  // width : $B2#I}(B
  // height : $B=DI}(B
  // title : $B%?%$%H%k(B
  explicit App(int width, int height, const char* title);
  App(const App& src) = delete;
  ~App();
  
  // window$B$,3+$$$F$$$k$+$I$&$+(B
  bool isOpen();
  
  // $BIA2h$G$-$k$h$&$K$9$k(B
  void letsStart();
  
  // $BGX7J?'$r@_Dj(B
  void setClearColor(float r, float g, float b);
  void setClearColor(const Color& color);
  
  // Key Events
  bool isPushKey(int key);
  bool isPullKey(int key);
  bool isPressKey(int key);
  
  // Mouse Events
  bool isPushMouse(int buttom);
  bool isPullMouse(int buttom);
  bool isPressMouse(int buttom);
  
  Vec2d mousePos() const;
};