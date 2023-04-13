#include<iostream>
#include<cmath>
#define M_PI 3.14159265

using namespace std;

class Vector
{
	double len;
	double angle;
public:
	Vector();

	Vector(double n_len, double n_angle);

	Vector(double len1);

	double get_len();
	double get_angle();

	double get_x();
	double get_y();

	double rotate(double n_angle);

	void print();

	Vector choose(Vector first, Vector second, Vector third, int num);

	Vector to_polar(double &x, double &y);

	Vector operator+(Vector& other);
	Vector operator/(int num);
};

