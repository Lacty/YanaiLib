
#pragma once

#include <iostream>
#include <Eigen/Core>
#include "color.hpp"
#include "graphic.hpp"


struct GLFWwindow;
using Vec2d = Eigen::Vector2d;

class App {
private:
  GLFWwindow* window_;

  // 背景色
  Color clear_color_;

  // windowのサイズ
  int window_w_;
  int window_h_;
  
  // マウスの位置
  Vec2d mouse_pos_;
  
  // マウスの位置を把握
  static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
  
  // windowのサイズを把握
  static void windowSizeCallBack(GLFWwindow* window, int width, int height);
  
  void setCallBackFunc();

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
  
  // 描画実行
  void begin();
  
  // 描画終了
  void end();
  
  // 背景色を設定
  void setClearColor(float r, float g, float b);
  void setClearColor(const Color& color);
  
  // マウスの位置を取得
  const Vec2d& mousePos() const;
};