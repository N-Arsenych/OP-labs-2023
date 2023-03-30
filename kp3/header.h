#include<iostream>

using namespace std;

class Point
{
	float x, y;
public:
	Point() { x = 0; y = 0; }

	Point(float m_x, float m_y)
	{
		x = m_x;
		y = m_y;
	}
	/*void Print(Point& p)
	{
		std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
	}*/

	float Get_x() { return x; }
	float Get_y() { return y; }
};

class Triangle
{
	Point p1, p2, p3;

	float change(Point& p1, Point& p2)
	{
		return sqrt(pow(p1.Get_x() - p2.Get_x(), 2) + pow(p1.Get_y() - p2.Get_y(), 2));
	}
public:
	Triangle()
	{
		p1 = { 0,0 };
		p2 = { 0,0 };
		p3 = { 0,0 };
	}

	Triangle(Point& point1, Point& point2, Point& point3)
	{
		p1 = point1;
		p2 = point2;
		p3 = point3;
	}


	float square()
	{
		float a = change(p1, p2);
		float b = change(p2, p3);
		float c = change(p1, p3);
		
		if (a + b <= c || b + c <= a || a + c <= b) {
			cout << "Triangle doesn't exist" << endl;
			return 1;
		}

		float p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}


	/*Triangle(float m_x1, float m_y1, float m_x2, float m_y2, float m_x3, float m_y3) {
		x1 = m_x1;
		y1 = m_y1;
		x2 = m_x2;
		y2 = m_y2;
		x3 = m_x3;
		y3 = m_y3;
	}

	void Print() {
		cout << "First point: " << "(" << x1 << ", " << y1 << ")" << "\nSecond point: " << "(" << x2 << ", " << y2 << ")" << "\nThird point: " << "(" << x3 << ", " << y3 << ")" << endl;
	}

	float square() {
		float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
		float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
		float p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}*/
	
};

Triangle get_Triangle(int);
int find_max_area(Triangle*, int);
void print_results(Triangle*, int, int);