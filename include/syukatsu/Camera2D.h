#ifndef CAMERA_2D_H_2013_12_18
#define CAMERA_2D_H_2013_12_18

#include "GLFW/glfw3.h"
#include "../math/Vector2.h"

class Camera2D
{  
  GLFWwindow *window; //glfwの関数に渡す為constにできない
  //画面上での位置, サイズ
  int viewportX;
  int viewportY;
  int viewportWidth;  //横幅
  int viewportHeight; //縦幅
  
  //ワールド座標におけるカメラの位置と視野幅,高さ
  Vector2 position;
  float frustumWidth;
  float frustumHeight;  
public:
  Camera2D(GLFWwindow *_window, float _frustumWidth, float _frustumHeight);  
  
  //:画面の場所, サイズを変える  
  void setViewportWidth(const float &width)
  {
    viewportWidth = width;
  }  
  void setViewportHeight(const float &height)
  {
    viewportHeight = height;
  }  
  void setViewportPosition(const int &x, const int &y)
  {
    viewportX = x;
    viewportY = y;
  }

  void setViewportAndMatrices() const;  
  Vector2 screenToWorld(const Vector2 &touch) const;  
};

#endif