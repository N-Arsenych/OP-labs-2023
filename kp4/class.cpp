#include"class.h"

Vector::Vector()
{
	len = 0; 
	angle = 0;
}

Vector::Vector(double n_len, double n_angle)
{
	len = n_len;
	angle = n_angle;
}

Vector::Vector(double n_len)
{
	len = n_len;
	angle = 0;
}

double Vector::get_len()
{
	return len;
}

double Vector::get_angle()
{
	return angle;
}

double Vector::get_x()
{
	return len * cos(angle);
}

double Vector::get_y()
{
	return len * sin(angle);
}

double Vector::rotate(double n_angle)
{
	angle = angle * (180 / M_PI);
	angle += n_angle;
	angle = fmod(angle, 360.0);
	std::cout << "Angle: " << angle << std::endl;
	angle = angle * (M_PI / 180);
	return angle;
}

void Vector::print()
{
	cout << "\tPolar (" << get_len() << ", " << get_angle() << ")" << endl;
	cout << "\tCartesian (" << get_x() << ", " << get_y() << ")" << endl;
}

Vector Vector::choose(Vector first, Vector second, Vector third, int num)
{
	if (num == 1)
	{
		return first;
	}
	else if (num == 2)
	{
		return second;
	}
	else if (num==3)
	{
		return third;
	}
	else
	{
		cout << "This vector doesn`t exist";
	}
}

Vector Vector::to_polar(double &x, double &y)
{
	double len = sqrt(x * x + y * y);
	double angle = atan2(y, x);

	return Vector(len, angle);
}

Vector Vector::operator+(Vector& other)
{
	double x = get_x() + other.get_x();
	double y = get_y() + other.get_y();

	//cout << "(" << x << ", " << y << ")";

	Vector result;
	return result.to_polar(x, y);
}

Vector Vector::operator/(int num)
{
	len = get_len() / num;
	
	Vector result(len, get_angle());
	return result;
}