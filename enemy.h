#ifndef ENEMY_H_
#define ENEMY_H_

#include "gen.h"

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

class EnemyBuffer{
    struct Enemy{
        Tetrahedron position;
        GLfloat vertices[36];
        GLfloat colors[36];
        GLuint vertexArray;
        GLuint vbuf;
        GLuint cbuf;
    };
    static std::vector<Enemy> enemy_;
    static GLuint shaders_;
public:
    static void load_shaders();
    static void draw(glm::mat4);
    static void create_enemy();
};

#endif // ENEMY_H_
