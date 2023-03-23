#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>


using namespace std;

struct Products
{
	string name;
	int b_day = 0;
	int b_month = 0;
	int b_year = 0;

	int e_day = 0;
	int e_month = 0;
	int e_year = 0;

	void Print() {
		cout << name << "\t\t" << b_day << "." << b_month << "." << b_year << "\t\t" << e_day << "." << e_month << "." << e_year << endl;
	}
};

int menu();
void delete_file(string);
void convert_date(string, int&, int&, int&);
void write(string, string, string);
void add_data(string, string, string);
void read(string);
int date(int, int, int);
void expiration(string, string, string);
bool check_date(int, int, int);
void operations(int, string, string, string);