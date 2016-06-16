
#pragma once
#include <set>
#include "vector.hpp"


class Mouse {
private:
  Vec2d pos_;

  std::set<int> push_;
  std::set<int> pull_;
  std::set<int> press_;

public:
  Mouse() :pos_(0, 0) {};

  void setButtonPush(int button) { push_.emplace(button); }
  void setButtonPull(int button) { pull_.emplace(button); }
  void setButtonPress(int button) { press_.emplace(button); }

  void frashInput() {
    push_.clear();
    pull_.clear();
  }

  void popButtonPress(int button) { press_.erase(press_.find(button)); }

  bool isPush(int button) {
    if (push_.find(button) == push_.end()) return false;
    push_.erase(push_.find(button));
    return true;
  }

  bool isPull(int button) {
    if (pull_.find(button) == pull_.end()) return false;
    pull_.erase(pull_.find(button));
    return true;
  }

  bool isPress(int button) {
    if (press_.find(button) == press_.end()) return false;
    return true;
  }

  Vec2d pos() const {
    return pos_;
  }

  void setPos(const double x, const double y) {
    pos_.x() = x;
    pos_.y() = y;
  } 
};
