
#include "random.hpp"


Random::Random() :
mt_(rand_()) {}

Random::Random(int seed) :
mt_(seed) {}

int Random::get(int start, int last) {
  return std::uniform_int_distribution<int>(start, last)(mt_);
}

float Random::get(float start, float last) {
  return std::uniform_real_distribution<float>(start, last)(mt_);
}

double Random::get(double start, double last) {
  return std::uniform_real_distribution<double>(start, last)(mt_);
}