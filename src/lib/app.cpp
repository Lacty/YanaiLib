
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
  
  // このクラスをOpenGLに登録
  glfwSetWindowUserPointer(window_, this);
  
  // コンテキスト作る
  glfwMakeContextCurrent(window_);
  
  // コールバック関数を設定
  setCallBackFunc();
  
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

void App::mouseButtomCallback(GLFWwindow* window, int button, int action, int mods) {
  auto app = static_cast<App*>(glfwGetWindowUserPointer(window));
  
  if (action == GLFW_PRESS) {
    app->mouse_.setButtonPush(button);
    app->mouse_.setButtonPress(button);
  }
  if (action == GLFW_RELEASE) {
    app->mouse_.setButtonPull(button);
    app->mouse_.popButtonPress(button);
  }
}

void App::mousePosCallBack(GLFWwindow* window, double xpos, double ypos) {
  auto app = static_cast<App*>(glfwGetWindowUserPointer(window));
  
  app->mouse_.setPos(xpos - app->window_w_ * 0.5f, -1 * (ypos - app->window_h_ * 0.5f));
}

void App::windowSizeCallBack(GLFWwindow* window, int width, int height) {
  auto app = static_cast<App*>(glfwGetWindowUserPointer(window));
  
  // 原点を画面の中央にする
  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(-width * 0.5f, width * 0.5f, -height * 0.5f, height * 0.5f, -0.0f, 1.0f);

  app->window_w_ = width;
  app->window_h_ = height;
}

void App::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
  auto app = static_cast<App*>(glfwGetWindowUserPointer(window));
  
  if (action == GLFW_PRESS) {
    app->key_.setKeyPush(key);
    app->key_.setKeyPress(key);
  }
  if (action == GLFW_RELEASE) {
    app->key_.setKeyPull(key);
    app->key_.popKeyPress(key);
  }
}

void App::setCallBackFunc() {
  glfwSetMouseButtonCallback(window_, mouseButtomCallback);
  glfwSetCursorPosCallback(window_, mousePosCallBack);
  glfwSetWindowSizeCallback(window_, windowSizeCallBack);
  glfwSetKeyCallback(window_, keyCallBack);
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
  key_.frashInput();
  mouse_.frashInput();

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

// Key Events
bool App::isPushKey(int key)  { return key_.isPush(key); }
bool App::isPullKey(int key)  { return key_.isPull(key); }
bool App::isPressKey(int key) { return key_.isPress(key); }

// Mouse Events
bool App::isPushMouse(int buttom)  { return mouse_.isPush(buttom); }
bool App::isPullMouse(int buttom)  { return mouse_.isPull(buttom); }
bool App::isPressMouse(int buttom) { return mouse_.isPress(buttom); }

Vec2d App::mousePos() const { return mouse_.pos(); }

void App::setMousePos(const Vec2d& pos) {
  glfwSetCursorPos(window_, pos.x(), pos.y());
  mouse_.setPos(pos.x(), pos.y());
}