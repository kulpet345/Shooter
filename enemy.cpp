#include "bullet.h"
#include "gen.h"
#include "enemy.h"
#include "intersection.h"
#include "shader.hpp"
#include "text2D.hpp"

#include <algorithm>
#include <string.h>
#include <string>

std::vector<EnemyBuffer::Enemy> EnemyBuffer::enemy_;
GLuint EnemyBuffer::shaders_ = 0;
double EnemyBuffer::next_time_ = 0;
UniformFloat EnemyBuffer::time_gen_ = UniformFloat(1.5, 3.5, 0);
size_t EnemyBuffer::killed_ = 0;

void EnemyBuffer::load_shaders(){
    shaders_ = LoadShaders("enemy.vertexshader", "enemy.fragmentshader");
}

void EnemyBuffer::draw(glm::mat4 camera) {
    glUseProgram(shaders_);
    for(auto& enemy: enemy_) {
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

    std::string msg = "Killed: " + std::to_string(killed_);
    printText2D(msg.c_str(), 0, 950, 40);
}

void EnemyBuffer::create_enemy(){
    enemy_.emplace_back();
    Enemy& current = enemy_.back();
    current.position = scale_tetrahedron(rand_rotate(get_tetrahedron(get_random_position())));
    static const GLfloat base_colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f
    };
    memcpy(current.colors, base_colors, sizeof(base_colors));
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

void EnemyBuffer::check_kills() {
    size_t ok = 0;
    for(size_t i = 0; i < enemy_.size(); i++){
        std::vector<std::vector<double> > me(4);
        for(size_t k = 0; k < 4; k++){
            me[k] = {enemy_[i].position[k].x, enemy_[i].position[k].y, enemy_[i].position[k].z};
        }
        bool alive = true;
        for(size_t j = 0; j < Bullets::models.size(); j++) {
            //std::vector<double> v = {Bullets::models[j][45].x, Bullets::models[j][45].y, Bullets::models[j][45].z};
            std::vector<double> v = {(Bullets::models[j][0].x + Bullets::models[j].back().x) / 2,
				                     (Bullets::models[j][0].y + Bullets::models[j].back().y) / 2,
				                     (Bullets::models[j][0].z + Bullets::models[j].back().z) / 2};
            //if(dist(me, v) < 0.0001){
            if (intersect(enemy_[i].position, v)) {
				Bullets::exist[j] = false;
                alive = false;
			}
            //    break;
            //}
        }
        if (alive) {
            enemy_[ok] = enemy_[i];
            ++ok;
        }
    }
    killed_ += enemy_.size() - ok;
    enemy_.resize(ok);
}
