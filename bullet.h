#include <chrono>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "objloader.hpp"
#include "bullet_geom.h"
#include <iostream>
#include <vector>


namespace Bullets {
	extern std::vector<std::vector<glm::vec3>> vertices;
	extern std::vector<std::vector<glm::vec2>> uvs;
	extern std::vector<std::vector<glm::vec3>> normals;
	extern std::vector<std::vector<glm::vec3>> models;
	
	extern std::vector<std::vector<glm::vec3>> polygon_vertices;
	//triangles-num, points-count
	extern std::vector<std::vector<glm::vec2>> polygon_uvs;
	extern std::vector<Point> polygon_sp;
	//triangles-num, points-count
	
	
	extern std::vector<Point> sp;
	extern GLuint uvbuffer;		
	extern GLuint vertexbuffer;
	extern double speed;
	extern GLuint TextureID;
	extern unsigned int Texture;
	extern double r;
	extern int last_cnt;
	extern std::vector<bool> exist;
	
	void LoadTexture(GLuint programID);
	void LoadObject(int cnt);
	void UpdateModels(std::chrono::duration<double> elapsed);
	void InsertModel(std::pair<glm::vec3, glm::vec3> camera);
	void EraseModel(int idx);
	void Draw();
	void CreateExist();
	void Clear();
	void IncreaseResolution();
	void DecreaseResolution();
};
