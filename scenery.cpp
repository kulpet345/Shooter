#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

#include "camera.h"
#include "shader.hpp"
#include "stb_image.h"

const double PI = 2 * acos(0);
const int floorTileSize = 4;
const int halfFloorDim = 128;
const float floorLevel = -5.0f;
const int skyStacks = 30;
const int skySectors = 200;
const double skyRadius = 95;
const double skySectorAngle = 2 * PI / skySectors;
const double skyStackAngle = 0.5 * PI / skyStacks;
//const glm::vec3 skyCenter = glm::vec3(0, floorLevel, 0);

struct Scenery{
    GLuint shaders, texture, sampler, UV, V;
};


Scenery floorScene, skyScene;

void setScenery(Scenery * what, const char * texture_file, GLuint shaders){
    what->shaders = shaders;
    //what->shaders = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );
    glGenTextures(1, &what->texture);
    glBindTexture(GL_TEXTURE_2D, what->texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(texture_file, &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    what->sampler  = glGetUniformLocation(what->shaders, "myTextureSampler");

    glGenBuffers(1, &what->V);
    glGenBuffers(1, &what->UV);
}

void initScenery(unsigned int shaders){
    setScenery(&floorScene, "wood.jpg", shaders);
    setScenery(&skyScene, "water.jpg", shaders);
}

void drawFloor(){
    glUseProgram(floorScene.shaders);
    static glm::vec3 vertices[6*4*halfFloorDim*halfFloorDim];
    static glm::vec2 uvs[6*4*halfFloorDim*halfFloorDim];
    int ptr = 0;
    for(int x = -halfFloorDim * floorTileSize; x < halfFloorDim * floorTileSize; x += floorTileSize){
        for(int y = -halfFloorDim * floorTileSize; y < halfFloorDim * floorTileSize; y += floorTileSize){
            vertices[ptr + 0] = vertices[ptr + 5] = glm::vec3(x, floorLevel, y);
            vertices[ptr + 1] = glm::vec3(x, floorLevel, y + floorTileSize);
            vertices[ptr + 2] = vertices[ptr + 3] = glm::vec3(x + floorTileSize, floorLevel, y + floorTileSize);
            vertices[ptr + 4] = glm::vec3(x + floorTileSize, floorLevel, y);
            uvs[ptr + 0] = uvs[ptr + 5] = glm::vec2(0, 0);
            uvs[ptr + 1] = glm::vec2(0, 1);
            uvs[ptr + 2] = uvs[ptr + 3] = glm::vec2(1, 1);
            uvs[ptr + 4] = glm::vec2(1, 0);
            ptr += 6;
        }
    }
    glBindBuffer(GL_ARRAY_BUFFER, floorScene.V);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, floorScene.UV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, floorScene.texture);
    glUniform1i(floorScene.sampler, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, floorScene.V);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, floorScene.UV);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);


    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

glm::vec3 getSkyCenter(){
    return glm::vec3(View::x, floorLevel, View::z);
}

glm::vec3 fromSpheric(double phi, double theta){
    return glm::vec3(skyRadius * cos(phi) * cos(theta), skyRadius * sin(phi), skyRadius * cos(phi) * sin(theta)) + getSkyCenter();
}

void drawSky(){
    glUseProgram(skyScene.shaders);
    static glm::vec3 vertices[6*skyStacks*skySectors];
    static glm::vec2 uvs[6*skyStacks*skySectors];
    int ptr = 0;
    for(int stack = 0; stack < skyStacks; stack++){
        for(int sector = 0; sector < skySectors; sector++){
            glm::vec3 downLeft = fromSpheric(skyStackAngle * stack, skySectorAngle * sector);
            glm::vec3 downRight = fromSpheric(skyStackAngle * stack, skySectorAngle * (1 + sector));
            glm::vec3 upLeft = fromSpheric(skyStackAngle * (1 + stack), skySectorAngle * sector);
            glm::vec3 upRight = fromSpheric(skyStackAngle * (1 + stack), skySectorAngle * (1 + sector));
            vertices[ptr + 0] = vertices[ptr + 3] = downLeft;
            vertices[ptr + 1] = upLeft;
            vertices[ptr + 2] = vertices[ptr + 5] = upRight;
            vertices[ptr + 4] = downRight;
            uvs[ptr + 0] = uvs[ptr + 3] = glm::vec2(0, 0);
            uvs[ptr + 1] = glm::vec2(0, 1);
            uvs[ptr + 2] = uvs[ptr + 5] = glm::vec2(1, 1);
            uvs[ptr + 4] = glm::vec2(1, 0);
            ptr += 6;
        }
    }
    glBindBuffer(GL_ARRAY_BUFFER, skyScene.V);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, skyScene.UV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, skyScene.texture);
    glUniform1i(skyScene.sampler, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, skyScene.V);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, skyScene.UV);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);


    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void drawScenery(){
    drawFloor();
    drawSky();
}
