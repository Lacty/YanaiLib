
#include "app.hpp"

#include <cassert>

#include <GLFW/glfw3.h>


App::App(int width, int height, const char* title) :
window_w_(width),
window_h_(height)
{
  // OpenGLの初期化に失敗した
  assert(glfwInit());
  
  // window作る
  window_ = glfwCreateWindow(window_w_, window_h_, title, NULL, NULL);
  if (!window_) {
    glfwTerminate();
    assert(!"window作れなかった");
  }
  
  // コンテキスト作る
  glfwMakeContextCurrent(window_);
  
  // fpsを60に絞る
  glfwSwapInterval(1);
  
  // 原点を画面の中央にする
  glViewport(0, 0, window_w_, window_h_);
  glOrtho(-window_w_ * 0.5f, window_w_ * 0.5f, -window_h_ * 0.5f, window_h_ * 0.5f, -0.0f, 1.0f);
}

App::~App() {
  // OpenGLの後片付け
  glfwTerminate();
}


bool App::isOpen() {
  // windowが開いているかどうか
  return !glfwWindowShouldClose(window_);
}

void App::letsStart() {
  end();
  begin();
}

void App::begin() {
  // 背景色を設定
  glClearColor(clear_color_.r, clear_color_.g, clear_color_.b, 1.0f);
  
  // 画面のバッファを削除
  glClear(GL_COLOR_BUFFER_BIT);
  
  // 色データを初期化
  glColor4f(1, 1, 1, 1);
}

void App::end() {
  // バッファを切り替え
  glfwSwapBuffers(window_);
  
  // 入力イベント受付
  glfwPollEvents();
}

void App::setClearColor(float r, float g, float b) {
  clear_color_ = Color(r, g, b);
}

void App::setClearColor(const Color &color) {
  clear_color_ = color;
}