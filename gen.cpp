#include "gen.h"
#include "random.h"

#include <math.h>
#include <utility>

Vec get_camera_position(){
    Vec answer;
    int viewport[4]; 
    glGetDoublev( GL_MODELVIEW_MATRIX, matModelView ); 
    glGetDoublev( GL_PROJECTION_MATRIX, matProjection ); 
    glGetIntegerv( GL_VIEWPORT, viewport ); 
    gluUnProject( (viewport[2]-viewport[0])/2 , (viewport[3]-viewport[1])/2, 
    0.0, matModelView, matProjection, viewport,  
    &answer.x,&answer.y,&answer.z);
    return answer;
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
