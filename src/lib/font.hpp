
#pragma once
#define FTGL_LIBRARY_STATIC

#include <FTGL/ftgl.h>
#include <string>


class Font {
private:
  FTPixmapFont font_;

public:
  Font() = default;
  Font(const std::string& path);

  void draw(const std::string& str, const float x, const float y, const int size);
  void draw(const wchar_t* str, const float x, const float y, const int size);
  void drawCenter(const std::string& str, const float x, const float y, const int size);
  void drawCenter(const wchar_t* str, const float x, const float y, const int size);
};
