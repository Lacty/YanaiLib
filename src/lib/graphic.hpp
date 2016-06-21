
#pragma once


class Color;

// 点を描画
// x y : 位置
// size : サイズ
// color : 色
void drawPoint(float x, float y, float size, bool smooth, const Color& color);


// 線を描画
// start : 始点
// end : 終点
// width : 幅
// color : 色
void drawLine(float start_x, float start_y,
              float end_x, float end_y,
              float width,
              const Color& color);


// 矩形を描画
// pos_x pos_y : 位置
// width : 横幅
// height : 縦幅
// line_w : 線の幅
// color : 色
void drawRect(float pos_x, float pos_y, float width, float height,
              float line_w, const Color& color);


// 塗りつぶした矩形を描画
// pos_x pos_y : 位置
// width : 横幅
// height : 縦幅
// color : 色
void drawFillRect(float pos_x, float pos_y, float width, float height,
                  const Color& color);