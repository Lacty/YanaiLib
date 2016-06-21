
#pragma once

#include <random>


class Random {
private:
  std::random_device rand_;
  std::mt19937_64    mt_;

public:
  Random();
  Random(int seed);
  
  int    get(int    start, int    last);
  float  get(float  start, float  last);
  double get(double start, double last);
};