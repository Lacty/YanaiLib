
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

  // 背景色
  Color clear_color_;

  // windowのサイズ
  int window_w_;
  int window_h_;
  
  Key key_;
  Mouse mouse_;
  
  // CallBack関数
  static void mouseButtomCallback(GLFWwindow* window, int button, int action, int mods);
  static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
  static void windowSizeCallBack(GLFWwindow* window, int width, int height);
  static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
  
  void setCallBackFunc();
  
  // 別座標系(左上原点)なので隠しておく
  void setMousePos(const Vec2d& pos);
  
  // 描画実行
  void begin();
  
  // 描画終了
  void end();

public:
  // width : 横幅
  // height : 縦幅
  // title : タイトル
  explicit App(int width, int height, const char* title);
  App(const App& src) = delete;
  ~App();
  
  // windowが開いているかどうか
  bool isOpen();
  
  // 描画できるようにする
  void letsStart();
  
  // 背景色を設定
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