#include "camera.h"
#include "speed.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

double View::angle = 0;
float View::x = 0;
float View::y = 0;
float View::z = 0;
double View::lastTime = 0;

const double PI = acos(-1.0);

void View::clamp_angle(){
    angle = fmod(angle, 2*PI);
    if(angle < 0)
        angle += 2*PI;
}

void recalcCamera(GLFWwindow * window){
    double currTime = glfwGetTime();
    double deltaTime = currTime - View::lastTime;
    View::lastTime = currTime;
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        View::angle += deltaTime * getSpeed(rSpeed);
        View::clamp_angle();
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        View::angle -= deltaTime * getSpeed(rSpeed);
        View::clamp_angle();
    }
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS){
        View::y -= deltaTime * getSpeed(vSpeed);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        View::y += deltaTime * getSpeed(vSpeed);
    }
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        View::x -= cos(View::angle) * deltaTime * getSpeed(hSpeed);
        View::z -= sin(View::angle) * deltaTime * getSpeed(hSpeed);
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        View::x += cos(View::angle) * deltaTime * getSpeed(hSpeed);
        View::z += sin(View::angle) * deltaTime * getSpeed(hSpeed);
    }
}

glm::mat4 getMVP(){
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    // Or, for an ortho camera :
    //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
    
    // Camera matrix
    glm::mat4 View       = glm::lookAt(
                                glm::vec3(View::x + cos(View::angle), View::y, View::z + sin(View::angle)),
                                glm::vec3(View::x, View::y, View::z),
                                glm::vec3(0,1,0)
                           );
    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around
    return MVP;
}
