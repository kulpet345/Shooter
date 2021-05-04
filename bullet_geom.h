#pragma once

#include <cmath>
#include <vector>



struct Point {
	double x;
	double y;
	double z;
};

double find_angle(std::vector<double> pt);

double find_oz(Point a);

double find_oy(Point a);

std::vector<double> mul(std::vector<std::vector<double>> mat, std::vector<double> pt);

std::vector<std::vector<double>> get_matr_oy(double angle);


std::vector<std::vector<double>> get_matr_oz(double angle);

Point get_rotation(Point a, double angy, double angz);

Point get_translation(Point a, Point b);

void get_angles(double& angle1, double& angle2, Point a);

std::vector<std::vector<double>> compose(std::vector<std::vector<double>> mat1,
                                    std::vector<std::vector<double>> mat2);

Point get_opposite(Point cur);

Point to_camera_view(Point pos, Point dir, Point cur);

std::vector<double> get_composite(Point dir, Point vert);

Point do_rot(std::vector<double> angles, Point A);
