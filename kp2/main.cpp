#include "header.h"

int main()
{
	string fname;
	cout << "Enter the name of your file" << endl;
	cin >> fname;
	
	char plus;

	do
	{	operations(menu(), fname);
		cout << "If you want to continue enter + " << endl;
		cin >> plus;
	} while (plus == '+');
	
}