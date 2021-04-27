#include "gen.h"
#include "random.h"

#include <math.h>
#include <string.h>
#include <utility>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

const float PI = acos(-1.0);

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

Tetrahedron scale_tetrahedron(Tetrahedron t){
    Tetrahedron out;
    Vec cen = (t[0] + t[1] + t[2] + t[3]) * 0.25;
    float scale = UniformFloat(3, 5, rand())();
    for(int i = 0; i < 4; i++)
        out[i] = cen + (t[i] - cen) * scale;
    return out;
}

Tetrahedron rand_rotate(Tetrahedron t){
    Vec cen = (t[0] + t[1] + t[2] + t[3]) * 0.25;
    Rotation rot;
    rot.base = cen;
    static float Z[3][3], Y[3][3], X[3][3];
    UniformFloat angle_gen(-PI, PI, rand());
    float zang = angle_gen();
    float yang = angle_gen();
    float xang = angle_gen();
    Z[0][0] = cos(zang); Z[0][1] = -sin(zang); Z[0][2] = 0;
    Z[1][0] = sin(zang); Z[1][1] = cos(zang); Z[1][2] = 0;
    Z[2][0] = Z[2][1] = 0; Z[2][2] = 1;
    Y[0][0] = cos(yang); Y[0][1] = 0; Y[0][2] = sin(yang);
    Y[1][0] = 0; Y[1][1] = 1; Y[1][2] = 0;
    Y[2][0] = -sin(yang); Y[2][1] = 0; Y[2][2] = cos(yang);
    X[0][0] = 1; X[0][1] = X[0][2] = 0;
    X[1][0] = 0; X[1][1] = cos(xang); X[1][2] = -sin(xang);
    X[2][0] = 0; X[2][1] = sin(xang); X[2][2] = cos(xang);
    memset(rot.mat, 0, sizeof(rot.mat));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                rot.mat[i][j] += Z[i][k] * Y[k][j];
            }
        }
    }
    memcpy(Y, rot.mat, sizeof(Y));
    memset(rot.mat, 0, sizeof(rot.mat));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                rot.mat[i][j] += Y[i][k] * X[k][j];
            }
        }
    }
    for(int i = 0; i < 4; i++)
        t[i] = rot(t[i]);
    return t;
}
