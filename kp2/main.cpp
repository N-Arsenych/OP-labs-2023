#include "header.h"

int main()
{
	string fname;
	string fnew1 = "output1.dat";
	string fnew2 = "output2.dat";

	cout << "Enter the name of your file" << endl;
	cin >> fname;
	char plus;
	do
	{	operations(menu(), fname, fnew1, fnew2);
		cout << "If you want to continue enter + " << endl;
		cin >> plus;
	} while (plus == '+');
	
}