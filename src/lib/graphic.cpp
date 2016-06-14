
#include "graphic.hpp"
#include "color.hpp"

#include <GLFW/glfw3.h>


void drawPoint(float x, float y, float size, const Color& color) {
  // 点を描画する位置を指定
  GLfloat vtx[] = { x, y };
  
  // 描画に使う頂点の配列をOpenGLに指定
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  
  // 描画する点のサイズ指定
  glPointSize(size);
  
  // 色を指定
  glColor4f(color.r, color.g, color.b, 1.0f);
  
  // 頂点配列で描画するモードに切り替えて
  // 点を描画
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_POINTS, 0, 1);
  
  // 描画が終わったら描画モードを元に戻す
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawLine(float start_x, float start_y,
              float end_x, float end_y,
              float width,
              const Color& color)
{
  // 描画する線分の始点と終点の座標(X, Y)を指定
  GLfloat vtx[] = {
    start_x, start_y,
    end_x, end_y
  };
  
  glVertexPointer(2, GL_FLOAT, 0, vtx);
  
  // 線分の太さを指定
  glLineWidth(width);
  
  // 色を指定
  glColor4f(color.r, color.g, color.b, 1.0f);
  
  // 描画
  glEnableClientState(GL_VERTEX_ARRAY);
  glDrawArrays(GL_LINES, 0, 2);
  
  glDisableClientState(GL_VERTEX_ARRAY);
}