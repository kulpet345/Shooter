#ifndef GEN_H_
#define GEN_H_

#include "geometry.h"

Vec get_camera_position();
Vec get_random_position(float min_dist = 10, float max_dist = 50);
Tetrahedron get_tetrahedron(Vec);

#endif // GEN_H_
