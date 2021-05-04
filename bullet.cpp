#include "bullet.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::vector<glm::vec3> Bullets::vertices;
std::vector<glm::vec2> Bullets::uvs;
std::vector<glm::vec3> Bullets::normals;
std::vector<std::vector<glm::vec3>> Bullets::models;
std::vector<Point> Bullets::sp;
GLuint Bullets::uvbuffer;		
GLuint Bullets::vertexbuffer;
double Bullets::speed;
GLuint Bullets::TextureID;
unsigned int Bullets::Texture;

void Bullets::LoadTexture(GLuint programID) {
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
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
	TextureID  = glGetUniformLocation(programID, "myTextureSampler");
}

void Bullets::LoadObject() {
	bool res = loadOBJ("bullet.obj", vertices, uvs, normals);
	for (int i = 0; i < vertices.size(); ++i) {
		    vertices[i].x /= 10;
		    vertices[i].y /= 10;
		    vertices[i].z /= 10;
	}
}

void Bullets::UpdateModels(std::chrono::duration<double> elapsed) {
	for (int j = 0; j < models.size(); ++j) {
		for (int i = 0; i < models[j].size(); ++i) {
			models[j][i].x += elapsed.count() * speed * sp[j].x;
			models[j][i].y += elapsed.count() * speed * sp[j].y;
			models[j][i].z += elapsed.count() * speed * sp[j].z;
		}
	}
}


void Bullets::InsertModel(std::pair<glm::vec3, glm::vec3> camera) {
    double x = camera.first.x;
	double y = camera.first.y;
	double z = camera.first.z;
	double x1 = camera.second.x;
	double y1 = camera.second.y;
	double z1 = camera.second.z;
	double norm = sqrt(x1 * x1 + y1 * y1 + z1 * z1);
	x1 /= norm;
	y1 /= norm;
	z1 /= norm;
	std::vector<glm::vec3> new_model(vertices.size());
	Point beg {
		(vertices[46].x + vertices[47].x + vertices[43].x + vertices[40].x) / 4,
		(vertices[46].y + vertices[47].y + vertices[43].y + vertices[40].y) / 4,
		(vertices[46].z + vertices[47].z + vertices[43].z + vertices[40].z) / 4
	};
	Point end{vertices[45].x, vertices[45].y, vertices[45].z};
	Point vert = get_translation(end, get_opposite(beg));
	auto angles = get_composite(Point{x1, y1, z1}, vert);

	for (int i = 0; i < vertices.size(); ++i) {
		Point pok = do_rot(angles, get_translation(
			Point{vertices[i].x, vertices[i].y, vertices[i].z},
			get_opposite(beg)
		));
		new_model[i].x += pok.x + beg.x + x + x1 / 10;
		new_model[i].y += pok.y + beg.y + y + y1 / 10;
		new_model[i].z += pok.z + beg.z + z + z1 / 10;
	}
	models.push_back(new_model);
	sp.push_back({x1, y1, z1});
}

void Bullets::Draw() {
	for (int i = 0; i < models.size(); ++i) {
		glGenBuffers(1, &uvbuffer);
	    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	    glGenBuffers(1, &vertexbuffer);
	    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	    glBufferData(GL_ARRAY_BUFFER, models[i].size() * sizeof(glm::vec3), &models[i][0], GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, Texture);
		glUniform1i(TextureID, 0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(
			 1,                                // attribute
			 2,                                // size
			 GL_FLOAT,                         // type
			 GL_FALSE,                         // normalized?
			 0,                                // stride
		 (void*)0                          // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, models[i].size() );
	}
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void Bullets::EraseModel(int idx) {
	models.erase(models.begin() + idx);
	sp.erase(sp.begin() + idx);
}
