
#include "font.hpp"
#include <iostream>


Font::Font(const std::string& str) :
font_(str.c_str()) {}


void Font::draw(const std::string& str, const float x, const float y, const int size) {
  font_.FaceSize(size);
  font_.Render(str.c_str(), (int)str.size(), FTPoint(x, y));
}

void Font::draw(const wchar_t* str, const float x, const float y, const int size) {
  font_.FaceSize(size);
  font_.Render(str, -1, FTPoint(x, y));
}

void Font::drawCenter(const std::string& str, const float x, const float y, const int size) {
  font_.FaceSize(size);
  float offset_x = (float)font_.BBox(str.c_str(), (int)str.size()).Upper().X() * 0.5f;
  font_.Render(str.c_str(), (int)str.size(), FTPoint(x - offset_x, y));
}

void Font::drawCenter(const wchar_t* str, const float x, const float y, const int size) {
  font_.FaceSize(size);
  float offset_x = (float)font_.BBox(str, -1).Upper().X() * 0.5f;
  font_.Render(str, -1, FTPoint(x - offset_x, y));
}