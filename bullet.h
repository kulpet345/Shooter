#include <chrono>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "objloader.hpp"
#include "bullet_geom.h"
#include <iostream>
#include <vector>


namespace Bullets {
	extern std::vector<glm::vec3> vertices;
	extern std::vector<glm::vec2> uvs;
	extern std::vector<glm::vec3> normals;
	extern std::vector<std::vector<glm::vec3>> models;
	extern std::vector<Point> sp;
	extern GLuint uvbuffer;		
	extern GLuint vertexbuffer;
	extern double speed;
	extern GLuint TextureID;
	extern unsigned int Texture;
	
	void LoadTexture(GLuint programID);
	void LoadObject();
	void UpdateModels(std::chrono::duration<double> elapsed);
	void InsertModel(std::pair<glm::vec3, glm::vec3> camera);
	void EraseModel(int idx);
	void Draw();
};
