#include <stdio.h>
#include <stdlib.h>
//#include "bullet_geom.h"
#include "bullet.h"
#include "shader.hpp"
//#include "objloader.hpp"
#include <iostream>
#include <chrono>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include <GL/gl3w.h>
//#include <GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
using namespace glm;

#include "camera.h"
#include "enemy.h"
#include "text2D.hpp"

int main(int argc, char ** argv)
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow( 1920, 1080, "Shooter", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	//Gluint MID = glGetUniformLocation(programID, "M");
	//Gluint VPID = glGetUniformLocation(programID, "VP");
	
	Bullets::LoadTexture(programID);
	Bullets::LoadObject();
	// Load the texture
	//GLuint Texture = loadDDS("uvmap.DDS");
	/*unsigned int Texture;
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);
 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
    int width, height, nrChannels;
    //unsigned char *data = stbi_load("texture.jpeg", &width, &height, &nrChannels, 0);
    unsigned char *data = stbi_load("stone_wall_texture.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
	
	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");
	*/

	// Read our .obj file
	//std::vector<glm::vec3> vertices;
	//std::vector<glm::vec2> uvs;
	//std::vector<glm::vec3> normals; // Won't be used at the moment.
	//bool res = loadOBJ("bullet.obj", vertices, uvs, normals);
	
	
	//for (int i = 0; i < vertices.size(); ++i) {
	//	vertices[i].x /= 10;
	//	vertices[i].y /= 10;
	//	vertices[i].z /= 10;
	//}
	
	//std::vector<std::vector<vec3>> models;
	//std::vector<std::vector<Point>> figures;
	//std::vector<Point> sp;
	
	//std::vector<std::vector<glm::vec3>> vertices;
	//std::vector<std::vector<glm::vec3>> a;
	//std::vector<std::vector<glm::vec2>> uvs;
	//std::vector<std::vector<glm::vec3>> normals;
	
	Bullets::speed = 0.001;
	
	auto start = std::chrono::high_resolution_clock::now();
	
	//GLuint uvbuffer;
	//glGenBuffers(1, &uvbuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	//glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
			
	//GLuint vertexbuffer;
	
	
    
    
    initText2D("Holstein.DDS");
    EnemyBuffer::load_shaders();

    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    EnemyBuffer::create_enemy();
    

    do {
        recalcCamera(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        auto MVP = getMVP();

        EnemyBuffer::try_create();
        EnemyBuffer::check_kills();

        EnemyBuffer::draw(MVP);
        
        glUseProgram(programID);

        
        auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
        
        double angle = View::angle;
        glm::vec3 pos{View::x, View::y, View::z};
        glm::vec3 dir{-std::cos(angle), 0, -std::sin(angle)};
        
        Bullets::UpdateModels(elapsed);
        
        
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
			std::pair<glm::vec3, glm::vec3> camera{pos, dir};
			Bullets::InsertModel(camera);
		}
	    
	    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	    
	    Bullets::Draw();
        

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    cleanupText2D();
    glfwTerminate();

    return 0;
}

