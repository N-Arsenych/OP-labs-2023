#include"header.h"

void intro()
{
	cout << "This program works with systems of linear equation." << endl;
	cout << "Namely with systems with 2 and 3 equations." << endl;
	cout << "The systems is generated randomly." << endl; 
	cout << "It first works with a 2 - equation system and then with a 3 - equation system";
}

double** create_main_slar(int n)
{
	double** a = new double* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 41 - 20;
		}
		cout << endl;
	}
	return a;
}

double* create_vector(int n)
{
	double* b = new double[n];

	for (int i = 0; i < n; i++)
	{
		b[i] = rand() % 41 - 20;
	}
	return b;
}

void delete_slar(double** a, double* b, int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	delete[] b;
}

void slar1()
{
	double** a1 = create_main_slar(2);
	double* b1 = create_vector(2);
	TSLE2 slar1(a1, b1);
	slar1.print_main_slar();
	slar1.print_vector();
	slar1.solve();
	delete_slar(a1, b1, 2);
}

void slar2()
{
	double** a2 = create_main_slar(3);
	double* b2 = create_vector(3);
	TSLE3 slar2(a2, b2);
	slar2.print_main_slar();
	slar2.print_vector();
	slar2.solve();
	delete_slar(a2, b2, 3);
}
