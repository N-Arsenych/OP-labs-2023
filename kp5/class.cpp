#include"class.h"

TSystemLinearEquation::TSystemLinearEquation(double** a, double* b, int n)
{
	this->n = n;
	A = new double* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			A[i][j] = a[i][j];
		}
	}
	B = new double[n];
	for (int i = 0; i < n; i++)
	{
		B[i] = b[i];
	}
}

TSystemLinearEquation::~TSystemLinearEquation()
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
	delete[] B;
}

void TSystemLinearEquation::print_main_slar()
{
	cout << "Main matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void TSystemLinearEquation::print_vector()
{
	cout << "Vector of free members:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": " << B[i] << endl;
	}
}

void TSLE2::solve()
{
	if (det!=0)
	{
		double x = (A[1][1] * B[0] - A[0][1] * B[1]) / det;
		double y = (A[0][0] * B[1] - A[1][0] * B[0]) / det;
		cout << "Results" << endl;
		cout << "x1 = " << x << endl;
		cout << "x2 = " << y << endl;
	}
}


void TSLE3::solve()
{
	double* X = new double[3];
	double factor, sum;

	// Прямий хід методу елімінації Гауса
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			factor = A[i][j] / A[j][j];
			for (int k = j + 1; k < n; k++) {
				A[i][k] -= factor * A[j][k];
			}
			B[i] -= factor * B[j];
			A[i][j] = 0.0;
		}
	}

	// Зворотний хід для знаходження невідомих
	X[n - 1] = B[n - 1] / A[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sum = B[i];
		for (int j = i + 1; j < n; j++) {
			sum -= A[i][j] * X[j];
		}
		X[i] = sum / A[i][i];
	}
	cout << "Result" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << " = " << X[i] << endl;
	}

	delete[] X;
}


