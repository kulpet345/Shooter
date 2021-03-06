#include "bullet.h"
#include "speed.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::vector<std::vector<glm::vec3>> Bullets::vertices;
std::vector<std::vector<glm::vec2>> Bullets::uvs;
std::vector<std::vector<glm::vec3>> Bullets::normals;
std::vector<std::vector<glm::vec3>> Bullets::models;

std::vector<std::vector<glm::vec3>> Bullets::polygon_vertices;
std::vector<std::vector<glm::vec2>> Bullets::polygon_uvs;
std::vector<Point> Bullets::polygon_sp;

std::vector<Point> Bullets::sp;
GLuint Bullets::uvbuffer;		
GLuint Bullets::vertexbuffer;
double Bullets::speed;
GLuint Bullets::TextureID;
unsigned int Bullets::Texture;
double Bullets::r;
std::vector<bool> Bullets::exist;
int Bullets::last_cnt = 10;

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

struct Res {
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> texture;
};


Res gen_points(int sectorCount, int stackCount) {
	//int sectorCount = 10;
	//int stackCount = 10;

// clear memory of prev arrays
std::vector<float> vertices;
std::vector<float> normals;
std::vector<float> texCoords;
float radius = 1.0;
float PI = 3.1415926;

float x, y, z, xy;                              // vertex position
float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
float s, t;                                     // vertex texCoord

float sectorStep = 2 * PI / sectorCount;
float stackStep = PI / stackCount;
float sectorAngle, stackAngle;

for(int i = 0; i <= stackCount; ++i)
{
    stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
    xy = radius * cosf(stackAngle);             // r * cos(u)
    z = radius * sinf(stackAngle);              // r * sin(u)

    // add (sectorCount+1) vertices per stack
    // the first and last vertices have same position and normal, but different tex coords
    for(int j = 0; j <= sectorCount; ++j)
    {
        sectorAngle = j * sectorStep;           // starting from 0 to 2pi

        // vertex position (x, y, z)
        x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
        y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);

        // normalized vertex normal (nx, ny, nz)
        nx = x * lengthInv;
        ny = y * lengthInv;
        nz = z * lengthInv;
        normals.push_back(nx);
        normals.push_back(ny);
        normals.push_back(nz);

        // vertex tex coord (s, t) range between [0, 1]
        s = (float)j / sectorCount;
        t = (float)i / stackCount;
        texCoords.push_back(s);
        texCoords.push_back(t);
    }
}
   return Res{vertices, normals, texCoords};
}

std::vector<int> get_indices(int stackCount, int sectorCount) {
	std::vector<int> indices;
    std::vector<int> lineIndices;
    //int stackCount = 10;
    //int sectorCount = 10;
    int k1, k2;
    for (int i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1);     // beginning of current stack
        k2 = k1 + sectorCount + 1;      // beginning of next stack

        for(int j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (stackCount-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }

            // store indices for lines
            // vertical lines for all stacks, k1 => k2
            lineIndices.push_back(k1);
            lineIndices.push_back(k2);
            if(i != 0)  // horizontal lines except 1st stack, k1 => k+1
            {
                lineIndices.push_back(k1);
                lineIndices.push_back(k1 + 1);
            }
        }
    }
    return indices;
}

void Bullets::LoadObject(int cnt) {
	std::cout << "Create object " << cnt << std::endl;
	//bool res = loadOBJ("bullet.obj", vertices, uvs, normals);
	Res res = gen_points(cnt, cnt);
	std::vector<int> idx = get_indices(cnt, cnt);
	vertices.push_back({});
	uvs.push_back({});
	normals.push_back({});
	
	for (int i = 0; i < idx.size(); ++i) {
		int num = idx[i];
		float x = res.vertices[num * 3];
		float y = res.vertices[num * 3 + 1];
		float z = res.vertices[num * 3 + 2];
		vertices.back().push_back({x, y, z});
		uvs.back().push_back({res.texture[num * 2], res.texture[num * 2 + 1]});
		normals.back().push_back({res.normals[num * 3],
			               res.normals[num * 3 + 1],
			               res.normals[num * 3 + 2]});
	}
	std::cout << "All right gen" << std::endl;
	for (int i = 0; i < vertices.back().size(); ++i) {
		    vertices.back()[i].x /= 10;
		    vertices.back()[i].y /= 10;
		    vertices.back()[i].z /= 10;
	}
}

void Bullets::UpdateModels(std::chrono::duration<double> elapsed) {
	for (int j = 0; j < models.size(); ++j) {
		for (int i = 0; i < models[j].size(); ++i) {
			models[j][i].x += elapsed.count() * getSpeed(speed) * sp[j].x;
			models[j][i].y += elapsed.count() * getSpeed(speed) * sp[j].y;
			models[j][i].z += elapsed.count() * getSpeed(speed) * sp[j].z;
		}
	}
	for (int j = 0; j < polygon_vertices.size(); ++j) {
		for (int i = 0; i < 3; ++i) {
			polygon_vertices[j][i].x += elapsed.count() * getSpeed(speed) / 3 * polygon_sp[j].x;
			polygon_vertices[j][i].y += elapsed.count() * getSpeed(speed) / 3 * polygon_sp[j].y;
			polygon_vertices[j][i].z += elapsed.count() * getSpeed(speed) / 3 * polygon_sp[j].z;
		}
	}
}


void Bullets::InsertModel(std::pair<glm::vec3, glm::vec3> camera) {
	//AddModel(last_cnt);
	Bullets::LoadObject(Bullets::last_cnt);
	std::cout << "Successful load object" << std::endl;
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
	std::vector<glm::vec3> new_model(vertices.back().size());
	//Point beg {
	//	(vertices[46].x + vertices[47].x + vertices[43].x + vertices[40].x) / 4,
	//	(vertices[46].y + vertices[47].y + vertices[43].y + vertices[40].y) / 4,
	//	(vertices[46].z + vertices[47].z + vertices[43].z + vertices[40].z) / 4
	//};
	Point beg {
		vertices.back()[0].x,
		vertices.back()[0].y,
		vertices.back()[0].z
	};
	//Point end{vertices[45].x, vertices[45].y, vertices[45].z};
	Point end {
		vertices.back().back().x,
		vertices.back().back().y,
		vertices.back().back().z
	};
	Point vert = get_translation(end, get_opposite(beg));
	auto angles = get_composite(Point{x1, y1, z1}, vert);

	for (int i = 0; i < vertices.back().size(); ++i) {
		Point pok = do_rot(angles, get_translation(
			Point{vertices.back()[i].x, vertices.back()[i].y, vertices.back()[i].z},
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
	    glBufferData(GL_ARRAY_BUFFER, uvs[i].size() * sizeof(glm::vec2), &uvs[i][0], GL_STATIC_DRAW);
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
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
	}
	
	for (int i = 0; i < polygon_vertices.size(); ++i) {
		glGenBuffers(1, &uvbuffer);
	    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	    glBufferData(GL_ARRAY_BUFFER, polygon_uvs[i].size() * sizeof(glm::vec2), &polygon_uvs[i][0], GL_STATIC_DRAW);
	    glGenBuffers(1, &vertexbuffer);
	    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	    glBufferData(GL_ARRAY_BUFFER, polygon_vertices[i].size() * sizeof(glm::vec3), &polygon_vertices[i][0], GL_STATIC_DRAW);
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
		glDrawArrays(GL_TRIANGLES, 0, polygon_vertices[i].size() );
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDeleteBuffers(1, &uvbuffer);
        glDeleteBuffers(1, &vertexbuffer);
	}
}

void Bullets::EraseModel(int idx) {
	models.erase(models.begin() + idx);
	sp.erase(sp.begin() + idx);
}


void Bullets::CreateExist() {
	exist.resize(models.size());
	std::fill(exist.begin(), exist.end(), true);
}

void Bullets::Clear() {
	std::vector<std::vector<glm::vec3>> new_models;
	std::vector<Point> new_sp;
	//extern std::vector<Point> sp;
	for (int i = 0; i < exist.size(); ++i) {
		if (exist[i]) {
			new_models.push_back(models[i]);
			new_sp.push_back(sp[i]);
		} else {
			for (int j = 0; j < models[i].size() / 3; ++j) {
				polygon_vertices.push_back({models[i][j * 3], models[i][j * 3 + 1], models[i][j * 3 + 2]});
			}
			for (int j = 0; j < models[i].size() / 3; ++j) {
				polygon_uvs.push_back({uvs[i][j * 3], uvs[i][j * 3 + 1], uvs[i][j * 3 + 2]});
			}
			for (int j = 0; j < models[i].size() / 3; ++j) {
				Point end{(models[i][j * 3].x + models[i][j * 3 + 1].x + models[i][j * 3 + 2].x) / 3,
					     (models[i][j * 3].y + models[i][j * 3 + 1].y + models[i][j * 3 + 2].y) / 3,
					     (models[i][j * 3].z + models[i][j * 3 + 1].z + models[i][j * 3 + 2].z) / 3};
			    Point beg{(models[i][0].x + models[i].back().x) / 2,
					      (models[i][0].y + models[i].back().y) / 2,
					      (models[i][0].z + models[i].back().z) / 2};
				Point sp_pol = get_translation(end, get_opposite(beg));
				double sq = sqrt(sp_pol.x * sp_pol.x + sp_pol.y * sp_pol.y + sp_pol.z * sp_pol.z);
				sp_pol.x /= sq;
				sp_pol.y /= sq;
				sp_pol.z /= sq;
				polygon_sp.push_back(sp_pol);
			}
			std::cout << "Killed" << std::endl;
		}
	}
	sp = new_sp;
	models = new_models;
}


void Bullets::IncreaseResolution() {
	last_cnt += 5;
	if (last_cnt > 100) {
		last_cnt = 100;
	}
}

void Bullets::DecreaseResolution() {
	last_cnt -= 5;
	if (last_cnt < 5) {
		last_cnt = 5;
	}
}

//void Bullets::AddModel() {
//	auto 
//}
