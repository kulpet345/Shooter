#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <array>

struct Vec{
    float x, y, z;
    Vec operator + (const Vec & v)const{
        return Vec{x + v.x, y + v.y, z + v.z};
    }
    Vec operator - (const Vec & v)const{
        return Vec{x - v.x, y - v.y, z - v.z};
    }
    Vec operator * (float d)const{
        return Vec{x * d, y * d, z * d};
    }
    void serialize(float* buf)const{
        buf[0] = x;
        buf[1] = y;
        buf[2] = z;
    }
};

using Tetrahedron = std::array<Vec, 4>;

#endif // GEOMETRY_H_
