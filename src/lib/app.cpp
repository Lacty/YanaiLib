
#include "app.hpp"

#include <cassert>


App::App(int width, int height, const char* title) :
window_w_(width),
window_h_(height)
{
  // OpenGLの初期化に失敗した
  assert(gl::glfwInit());
  
  // window作る
  window_ = gl::glfwCreateWindow(window_w_, window_h_, title, NULL, NULL);
  if (!window_) {
    gl::glfwTerminate();
    assert(!"window作れなかった");
  }
  
  // コンテキスト作る
  gl::glfwMakeContextCurrent(window_);
  
  // fpsを60に絞る
  gl::glfwSwapInterval(1);
  
  // 原点を画面の中央にする
  gl::glViewport(0, 0, window_w_, window_h_);
  gl::glOrtho(-window_w_ * 0.5f, window_w_ * 0.5f, -window_h_ * 0.5f, window_h_ * 0.5f, -0.0f, 1.0f);
}

App::~App() {
  // OpenGLの後片付け
  gl::glfwTerminate();
}


bool App::isOpen() {
  // windowが開いているかどうか
  return !gl::glfwWindowShouldClose(window_);
}

void App::letsStart() {
  // 背景色を設定
  gl::glClearColor(clear_color_.r, clear_color_.g, clear_color_.b, 1.0f);

  // 画面のバッファを削除
  gl::glClear(GL_COLOR_BUFFER_BIT);
  
  // 色データを初期化
  gl::glColor4f(1, 1, 1, 1);
  
  // バッファを切り替え
  gl::glfwSwapBuffers(window_);
  
  // 入力イベント受付
  gl::glfwPollEvents();
}

void App::setClearColor(float r, float g, float b) {
  clear_color_ = Color(r, g, b);
}

void App::setClearColor(const Color &color) {
  clear_color_ = color;
}