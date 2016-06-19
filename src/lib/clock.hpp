
#pragma once

#include <chrono>


class Clock {
private:
  std::chrono::system_clock::time_point start_;   // 計測し始めの時刻
  std::chrono::system_clock::time_point last_;    // 前のフレームを処理した際の時刻
  std::chrono::system_clock::time_point current_; // 現在の時刻

public:
  Clock();
  
  // 計測し始めた時間を現在へリセット
  void reset();
  
  // 計測し始めた時間から現在時刻との差を取得
  // sec
  double time();
  
  // 前のフレームからの差を取得
  double dura();
};