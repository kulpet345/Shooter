#include <iostream>
#include <vector>
#include <cmath>
#include "geometry.h"
#include "bullet.h"
#include "enemy.h"

std::vector<double> minus(std::vector<double> pt1, std::vector<double> pt2) {
	return std::vector<double>{pt1[0] - pt2[0], pt1[1] - pt2[1], pt1[2] - pt2[2]};
}


bool intersect(Tetrahedron h, std::vector<double> bullet_center) {
	double r = Bullets::r;
	double r1 = get_radius(h);
	Vec c = get_center(h);
	double dist = sqrt((c.x - bullet_center[0]) * (c.x - bullet_center[0]) + 
	               (c.y - bullet_center[1]) * (c.y - bullet_center[1]) +
	               (c.z - bullet_center[2]) * (c.z - bullet_center[2]));
	return dist < r + r1;
}

/*double det3(std::vector<std::vector<double>> vec) {
	return abs(vec[0][0] * vec[1][1] * vec[2][2] - vec[0][0] * vec[1][2] * vec[2][1]
	           + vec[0][1] * vec[1][2] * vec[2][0] - vec[0][1] * vec[1][0] * vec[2][2]
	           + vec[0][2] * vec[1][0] * vec[2][1] - vec[0][2] * vec[1][1] * vec[2][0]) / 6;
}

double det2(std::vector<double> vec1, std::vector<double> vec2) {
	std::vector<double> vec{vec1[1] * vec2[2] - vec1[2] * vec2[1],
		vec1[2] * vec2[0] - vec1[0] * vec2[2],
		vec1[0] * vec2[1] - vec1[1] * vec2[0]};
	return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]) / 2;
}


bool intersect(std::vector<std::vector<double>> pyr, std::vector<double> pt) {
	double s = 0;
	for (int i = 0; i < 4; ++i) {
		std::vector<std::vector<double>> vec;
		for (int j = 0; j < 4; ++j) {
			if (j != i) {
				vec.push_back(minus(pyr[j], pt));
			}
		}
		s += det3(vec);
	}
	std::vector<std::vector<double>> vec{minus(pyr[1], pyr[0]),
		                                 minus(pyr[2], pyr[0]),
		                                 minus(pyr[3], pyr[0])};
	return abs(s - det3(vec)) < 1e-5;
}


double sq(std::vector<std::vector<double>> pyr, std::vector<double> pt) {
	double s = 1e18;
	for (int i = 0; i < 4; ++i) {
		double sq;
		std::vector<std::vector<double>> vec;
		for (int j = 0; j < 4; ++j) {
			if (j != i) {
				vec.push_back(minus(pyr[j], pt));
			}
		}
		if (i == 0) {
			sq = det2(minus(pyr[2], pyr[1]), minus(pyr[3], pyr[1]));
		}
		if (i == 1) {
			sq = det2(minus(pyr[2], pyr[0]), minus(pyr[3], pyr[0]));
		}
		if (i == 2) {
			sq = det2(minus(pyr[3], pyr[0]), minus(pyr[1], pyr[0]));
		}
		if (i == 3) {
			sq = det2(minus(pyr[1], pyr[0]), minus(pyr[2], pyr[0]));
		}
		s = std::min(det3(vec) / sq, s);
	}
	return s;
}


double dist(std::vector<std::vector<double>> pyr, std::vector<double> pt) {
	if (intersect(pyr, pt)) {
		return 0.0;
	}
	return sq(pyr, pt);
}
*/


//int main() {
//	std::vector<std::vector<double>> pyr{{0, 1, 2}, {1, 2, 3}, {2, 3, 7}, {3, 2, 11}};
//	std::vector<double> pt{0, 1, 2};
//	std::cout << intersect(pyr, pt);
//}



