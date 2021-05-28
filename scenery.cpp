#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"
#include "stb_image.h"

const int floorTileSize = 128;
const int halfFloorDim = 40;
const float floorLevel = -5.0f;

GLuint floorShaders;
GLuint floorTexture;
GLuint floorSampler;
GLuint floorUV, floorV;

void initScenery(){
    floorShaders = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );
    glGenTextures(1, &floorTexture);
    glBindTexture(GL_TEXTURE_2D, floorTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("wood.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    floorSampler  = glGetUniformLocation(floorShaders, "myTextureSampler");

    glGenBuffers(1, &floorV);
    glGenBuffers(1, &floorUV);
}

void drawScenery(){
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
    glBindBuffer(GL_ARRAY_BUFFER, floorV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, floorUV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

    glUseProgram(floorShaders);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    glUniform1i(floorSampler, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, floorV);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, floorUV);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);


    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
