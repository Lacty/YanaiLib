
#include "clock.hpp"


Clock::Clock() :
start_(std::chrono::system_clock::now()),
last_(std::chrono::system_clock::now()),
current_(std::chrono::system_clock::now()) {}


void Clock::reset() {
  start_ = std::chrono::system_clock::now();
}

double Clock::time() {
  current_ = std::chrono::system_clock::now();
  return std::chrono::duration<double>(current_ - start_).count();
}

double Clock::dura() {
  current_ = std::chrono::system_clock::now();
  double duration = std::chrono::duration<double>(current_ - last_).count();
  last_ = std::chrono::system_clock::now();
  return duration;
}