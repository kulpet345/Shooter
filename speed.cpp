#include <GLFW/glfw3.h>

double restoreTime = 0;

double getSpeed(double speed){
    return glfwGetTime() < restoreTime ? speed * 0.33 : speed;
}

void slowMotion(){
    restoreTime = glfwGetTime() + 5;
}
