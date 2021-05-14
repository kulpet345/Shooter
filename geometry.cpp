#include "geometry.h"

#include <algorithm>

Vec get_center(const Tetrahedron& t){
    return (t[0] + t[1] + t[2] + t[3]) * 0.25;
}

float get_radius(const Tetrahedron& t){
    Vec cen = get_center(t);
    float ans = (cen - t[0]).norm();
    for(int i = 1; i < 4; i++)
        ans = std::max(ans, (cen - t[i]).norm());
    return ans;
}
