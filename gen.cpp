#include "gen.h"
#include "random.h"

#include <math.h>
#include <utility>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

Vec get_camera_position(){
    GLdouble x, y, z;
    int viewport[4]; 
    GLdouble matModelView[16];
    GLdouble matProjection[16];
    glGetDoublev( GL_MODELVIEW_MATRIX, matModelView ); 
    glGetDoublev( GL_PROJECTION_MATRIX, matProjection ); 
    glGetIntegerv( GL_VIEWPORT, viewport ); 
    gluUnProject( (viewport[2]-viewport[0])/2 , (viewport[3]-viewport[1])/2, 
    0.0, matModelView, matProjection, viewport,  
    &x, &y, &z);
    return Vec{(float)x, (float)y, (float)z};
}

Vec get_random_position(float min_dist, float max_dist){
    static const float PI = acos(-1.0);
    Vec me = get_camera_position();
    UniformFloat distGen(min_dist, max_dist, rand());
    float dist = distGen();
    UniformFloat zGen(-dist, dist, rand());
    UniformFloat longitudeGen(0, 2*PI, rand());
    float z = zGen();
    float cosLatitude = z/dist;
    float sinLatitude = sqrt(std::max((float)0, 1 - cosLatitude * cosLatitude));
    float longitude = longitudeGen();
    return Vec{dist * cos(longitude) * sinLatitude, dist * sin(longitude) * sinLatitude, z} + me;
}

Tetrahedron get_tetrahedron(Vec position){
    return {position + Vec{0.0f, 0.0f, 1.0f}, position + Vec{0.0f, 0.57735f, 0.0f}, position + Vec{-0.5f, -0.28868f, 0.0f}, position + Vec{0.5f, -0.28868f, 0.0f}};
}
