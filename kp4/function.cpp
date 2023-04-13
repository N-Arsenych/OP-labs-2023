#include"header.h"

void intro()
{
	cout << "This program works with vectors that given by polar coordinates." << endl;
	cout << "it find (x, y), sum, rotate angle and reduce the vector.\n" << endl;
}

void head_function()
{
	double len, angle;
	cout << "Firs vector is (len = 0; angle = 0)" << endl;
	Vector B1;
	cout << "Second vector (enter only lenght): ";
	cin >> len;
	Vector B2(len);
	cout << "Third vector (enter the lenght and the angle in degrees): ";
	cin >> len >> angle;
	angle = to_rad(angle);
	Vector B3(len, angle);

	show_vectors(B1, B2, B3);

	choose_to_rotate(B1, B2, B3);
	show_vectors(B1, B2, B3);

	choose_to_reduce(B1, B2, B3);
	show_vectors(B1, B2, B3);

	choose_to_sum(B1, B2, B3);
	show_vectors(B1, B2, B3);
}

double to_rad(double angle)
{
	return angle * (M_PI / 180);
}

void show_vectors(Vector &first, Vector&second, Vector&third)
{
	cout << "\nFirst vector:" << endl;
	first.print();
	cout << "Second vector:" << endl;
	second.print();
	cout << "Third vector:" << endl;
	third.print();
}

void rotate_angle(Vector& B)
{
	int plus_angle;
	cout << "Enter how many degrees you want to rotate the angle of this vector: ";
	cin >> plus_angle;
	plus_angle;
	B.rotate(plus_angle);
}

void reduce(Vector& B)
{
	int num;
	cout << "Enter the number you want to reduce the vector: ";
	cin >> num;
	B = B / num;
}

void choose_to_rotate(Vector&first, Vector&second, Vector&third)
{
	int ch;
	cout << "Choose the vector you want to rotate(enter the num of the vector): ";
	cin >> ch;

	if (ch == 1)
	{
		rotate_angle(first);
	}
	else if (ch == 2)
	{
		rotate_angle(second);
	}
	else if (ch == 3)
	{
		rotate_angle(third);
	}
	else
	{
		cout << "This vector doesn`t exist";
	}

}

void choose_to_reduce(Vector& first, Vector& second, Vector& third)
{
	int ch;
	cout << "Choose the vector you want to reduce(enter the num of the vector): ";
	cin >> ch;

	if (ch == 1)
	{
		reduce(first);
	}
	else if (ch == 2)
	{
		reduce(second);
	}
	else if (ch == 3)
	{
		reduce(third);
	}
	else
	{
		cout << "This vector doesn`t exist";
	}

	/*Vector res = res.choose(first, second, third, ch);
	reduce(res);*/
}

void choose_to_sum(Vector& first, Vector& second, Vector& third)
{
	int ch;
	cout << "Choose a vector that will be the sum of the other two(enter the num of the vector): ";
	cin >> ch;
	
	if (ch == 1)
	{
		first = second + third;
	}
	else if (ch == 2)
	{
		second = first + third;
	}
	else if (ch == 3)
	{
		third = first + second;
	}
	else
	{
		cout << "This vector doesn`t exist";
	}
}