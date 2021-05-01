#ifndef CAMERA_H_
#define CAMERA_H_

#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

const float hSpeed = 1.5f;
const float vSpeed = 1.0f;
const double rSpeed = 2 * acos(-1.0) / 5;


struct View{
    static double angle;
    static float x, y, z;
    static double lastTime;
    static void clamp_angle();
};

void recalcCamera(GLFWwindow*);
glm::mat4 getMVP();

#endif // CAMERA_H_
