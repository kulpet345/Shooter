#include "gen.h"
#include "enemy.h"
#include "shader.hpp"

#include <string.h>


std::vector<EnemyBuffer::Enemy> EnemyBuffer::enemy_;
GLuint EnemyBuffer::shaders_ = 0;
double EnemyBuffer::next_time_ = 0;
UniformFloat EnemyBuffer::time_gen_ = UniformFloat(1.5, 3.5, 0);

void EnemyBuffer::load_shaders(){
    shaders_ = LoadShaders("enemy.vertexshader", "enemy.fragmentshader");
}

void EnemyBuffer::draw(glm::mat4 camera){
    glUseProgram(shaders_);
    for(auto& enemy: enemy_){
        auto matrix = glGetUniformLocation(shaders_, "MVP");
        glm::mat4 MVP;
        memcpy(&MVP, &camera, sizeof(MVP));
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &MVP[0][0]);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, enemy.vbuf);
        glVertexAttribPointer(
            0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, enemy.cbuf);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, 12);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }
}

void EnemyBuffer::create_enemy(){
    enemy_.emplace_back();
    Enemy& current = enemy_.back();
    current.position = get_tetrahedron(get_random_position());
    memset(current.colors, 0, 36 * sizeof(GLfloat));
    for(int i = 0; i < 36; i += 3)
        current.colors[i] = 1.0f;
    GLfloat * ptr = current.vertices;
    for(int exclude = 0; exclude < 4; exclude++){
        for(int i = 0; i < 4; i++){
            if(i != exclude){
                current.position[i].serialize(ptr);
                ptr += 3;
            }
        }
    }
    glGenVertexArrays(1, &current.vertexArray);
    glBindVertexArray(current.vertexArray);
    glGenBuffers(1, &current.vbuf);
    glBindBuffer(GL_ARRAY_BUFFER, current.vbuf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(current.vertices), current.vertices, GL_STATIC_DRAW);
    glGenBuffers(1, &current.cbuf);
    glBindBuffer(GL_ARRAY_BUFFER, current.cbuf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(current.colors), current.colors, GL_STATIC_DRAW);
}

void EnemyBuffer::try_create(){
    double t = glfwGetTime();
    if(t > next_time_){
        create_enemy();
        next_time_ += time_gen_();
    }
}
