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
#include "scenery.h"
#include "speed.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
		double angle = View::angle;
        glm::vec3 pos{View::x, View::y, View::z};
        glm::vec3 dir{-std::cos(angle), 0, -std::sin(angle)};
        std::pair<glm::vec3, glm::vec3> camera{pos, dir};
		Bullets::InsertModel(camera);
	}
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        slowMotion();
    }
}

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

    //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

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
	
	Bullets::LoadTexture(programID);
	Bullets::LoadObject();
	Bullets::speed = 0.001;
	initScenery(programID);

	auto start = std::chrono::high_resolution_clock::now();
	
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
        Bullets::CreateExist();
        EnemyBuffer::check_kills();
        Bullets::Clear();

        drawScenery();        
        EnemyBuffer::draw(MVP);
        
        glUseProgram(programID);

        
        auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
        
        Bullets::UpdateModels(elapsed);
        
        glfwSetKeyCallback(window, key_callback);
	    
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

