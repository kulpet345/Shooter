#include "bullet_geom.h"


double find_angle(std::vector<double> pt) {
	return std::atan2(pt[1], pt[0]);
}

double find_oz(Point a) {
	return find_angle(std::vector<double>{a.x / sqrt(a.x * a.x + a.y * a.y),
		                           a.y / sqrt(a.x * a.x + a.y * a.y)});
}

double find_oy(Point a) {
	return find_angle(std::vector<double>{a.x / sqrt(a.x * a.x + a.z * a.z),
		                           a.z / sqrt(a.x * a.x + a.z * a.z)});
}

std::vector<double> mul(std::vector<std::vector<double>> mat, std::vector<double> pt) {
	std::vector<double> ans(pt.size());
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[i].size(); ++j) {
			ans[i] += mat[i][j] * pt[j];
		}
	}
	return ans;
}

std::vector<std::vector<double>> get_matr_oy(double angle) {
	std::vector<std::vector<double>> mat = {
		{std::cos(angle), 0, std::sin(angle)}, 
		{0, 1, 0},
		{-std::sin(angle), 0, std::cos(angle)}
	};
	return mat;
}

std::vector<std::vector<double>> get_matr_oz(double angle) {
	std::vector<std::vector<double>> mat = {
		{std::cos(-angle), -std::sin(-angle), 0}, 
		{std::sin(-angle), std::cos(-angle), 0},
		{0, 0, 1}
	};
	return mat;
}

Point get_rotation(Point a, double angy, double angz) {
	std::vector<double> pt(3);
	pt[0] = a.x;
	pt[1] = a.y;
	pt[2] = a.z;
	std::vector<std::vector<double>> maty = get_matr_oy(angy);
	std::vector<std::vector<double>> matz = get_matr_oz(angz);
	std::vector<double> pt1 = mul(matz, mul(maty, pt));
	return Point{pt1[0], pt1[1], pt1[2]};	
}

Point get_translation(Point a, Point b) {
	return Point{a.x + b.x, a.y + b.y, a.z + b.z};
}

void get_angles(double& angle1, double& angle2, Point a) {
	angle1 = find_oy(a);
	//return;
	std::vector<double> d{a.x, a.y, a.z};
	auto c = mul(get_matr_oy(angle1), d);
	//return;
	Point b{c[0], c[1], c[2]};
	angle2 = find_oz(b);
	//mul(, b);
}

//void inverse_rot(double& angle1, double& angle2) {
//	std::swap(angle1, angle2);
//	angle2 = -angle2;
//	angle1 = -angle1;
//}

std::vector<std::vector<double>> compose(std::vector<std::vector<double>> mat1,
                                    std::vector<std::vector<double>> mat2) {
	std::vector<std::vector<double>> ans(mat1.size());
	for (int i = 0; i < mat1.size(); ++i) {
		ans[i].resize(mat2[0].size());
		for (int j = 0; j < mat2[0].size(); ++j) {
			for (int k = 0; mat1[i].size(); ++k) {
				ans[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return ans;
}

Point get_opposite(Point cur) {
	return Point{-cur.x, -cur.y, -cur.z};
}

Point to_camera_view(Point pos, Point dir, Point cur) {
	Point cur_dir = get_translation(cur, get_opposite(pos));
	double angley, anglez;
	get_angles(angley, anglez, dir);
	double angley1, anglez1;
	get_angles(angley1, anglez1, cur_dir);
	
	
	auto mat = get_matr_oy(angley);
	auto mat1 = get_matr_oz(anglez);
	auto mat2 = get_matr_oy(-angley1);
	auto mat3 = get_matr_oz(-anglez1);
	
	std::vector<double> cur_dir1{cur_dir.x, cur_dir.y, cur_dir.z};
	
	std::vector<double> res = mul(mat2, mul(mat3, mul(mat1, mul(mat, cur_dir1))));
	
	return get_translation(Point{res[0], res[1], res[2]}, pos);
}

std::vector<double> get_composite(Point dir, Point vert) {
	double angley, anglez;
	get_angles(angley, anglez, vert);
	double angley1, anglez1;
	get_angles(angley1, anglez1, dir);
	return std::vector<double>{angley, anglez, angley1, anglez1};
}

Point do_rot(std::vector<double> angles, Point A) {
	std::vector<double> pt{A.x, A.y, A.z};
	auto mat = get_matr_oy(angles[0]);
	auto mat1 = get_matr_oz(angles[1]);
	auto mat2 = get_matr_oy(-angles[2]);
	auto mat3 = get_matr_oz(-angles[3]);
	std::vector<double> res = mul(mat2, mul(mat3, mul(mat1, mul(mat, pt))));
	return Point{res[0], res[1], res[2]};
}

