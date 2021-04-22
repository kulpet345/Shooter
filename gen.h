#ifndef GEN_H_
#define GEN_H_

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
};

Vec get_camera_position();
Vec get_random_position(float min_dist = 10, float max_dist = 50);

#endif // GEN_H_
