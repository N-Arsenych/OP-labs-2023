#pragma once
#include<iostream>
#include<cmath>

using namespace std;

class TSystemLinearEquation
{
protected:
	double** A;
	double* B;    
	int n;		  

public:

	TSystemLinearEquation(double** a, double* b, int n);

	double** get_A() { return A; }
	double* get_B() { return B; }


	virtual void solve() = 0;

	void print_main_slar();

	void print_vector();

	~TSystemLinearEquation();
};


class TSLE2 : public TSystemLinearEquation
{
	double det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

public:

	TSLE2(double** a, double* b) :TSystemLinearEquation(a, b, 2) {}

	using TSystemLinearEquation::print_main_slar;

	using TSystemLinearEquation::print_vector;

	void solve();

};


class TSLE3 : public TSystemLinearEquation
{
public:

	TSLE3(double** a, double* b):TSystemLinearEquation(a, b, 3) {}

	using TSystemLinearEquation::print_main_slar;

	using TSystemLinearEquation::print_vector;

	void solve();

};