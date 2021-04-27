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

struct Rotation{
    Vec base;
    float mat[3][3];
    Vec operator () (const Vec & v)const{
        Vec pt = v - base;
        return base + Vec{mat[0][0] * pt.x + mat[0][1] * pt.y + mat[0][2] * pt.z,
                   mat[1][0] * pt.x + mat[1][1] * pt.y + mat[1][2] * pt.z,
                   mat[2][0] * pt.x + mat[2][1] * pt.y + mat[2][2] * pt.z};
    }
};

#endif // GEOMETRY_H_
