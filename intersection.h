#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> minus(std::vector<double> pt1, std::vector<double> pt2) {
	return std::vector<double>{pt1[0] - pt2[0], pt1[1] - pt2[1], pt1[2] - pt2[2]};
}

double det(std::vector<std::vector<double>> vec) {
	return abs(vec[0][0] * vec[1][1] * vec[2][2] - vec[0][0] * vec[1][2] * vec[2][1]
	           + vec[0][1] * vec[1][2] * vec[2][0] - vec[0][1] * vec[1][0] * vec[2][2]
	           + vec[0][2] * vec[1][0] * vec[2][1] - vec[0][2] * vec[1][1] * vec[2][0]);
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
		s += det(vec);
	}
	std::vector<std::vector<double>> vec{minus(pyr[1], pyr[0]),
		                                 minus(pyr[2], pyr[0]),
		                                 minus(pyr[3], pyr[0])};
	return abs(s - det(vec)) < 1e-5;
}


//int main() {
//	std::vector<std::vector<double>> pyr{{0, 1, 2}, {1, 2, 3}, {2, 3, 7}, {3, 2, 11}};
//	std::vector<double> pt{0, 1, 2};
//	std::cout << intersect(pyr, pt);
//}



