
#pragma once


class Color;

// 点を描画
// x y : 位置
// size : サイズ
// color : 色
void drawPoint(float x, float y, float size, const Color& color);


// 線を描画
// start : 始点
// end : 終点
// width : 幅
// color : 色
void drawLine(float start_x, float start_y,
              float end_x, float end_y,
              float width,
              const Color& color);