#include "header.h"

int menu() {
	int ch;
	cout << "Choose what to do:\n1 - write to file\n2 - read file\n3 - sort products\n4 - add data to file\n5 - delete file" << endl;
	cin >> ch;
	return ch;
}

void delete_file(string fname) 
{
	{
		if (remove(fname.c_str()) != 0)
		{
			cout << "Error deleting file" << endl;
		}
		else
		{
			cout << "File deleted successfully" << endl;
		}
	}
}

void convert_date(string date, int &day, int &month, int& year) {
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(3, 5));
	year = stoi(date.substr(6, 10));
}

void write(string fname, string date_b, string date_e) {
	ofstream in(fname, ios::binary | ios::out);
	Products p;
	if (!in)
	{
		cout << "ERROR. File wasn`t opened/created" << endl;
	}
	else {
		
		char flag;
		do {
			cout << "Enter name: ";
			cin >> p.name;
			cout << "Enter date of manufacture: ";
			cin >> date_b;
			cout << "Enter expiration date: ";
			cin >> date_e;
			
			convert_date(date_b, p.b_day, p.b_month, p.b_year);
			convert_date(date_e, p.e_day, p.e_month, p.e_year);
			if (!check_date(p.b_day, p.b_month, p.b_year) || !check_date(p.e_day, p.e_month, p.e_year))
			{
				cout << "Error. Wrong date" << endl;
			}
			else {
				in.write((char*)&p, sizeof(p));
			}
			cout << "Enter <Y> if you want to continue: ";
			cin >> flag;
		} while (flag == 'Y' || flag == 'y');
		in.close();
	}
}

void add_data(string fname, string date_b, string date_e) {
	ofstream in(fname, ios::binary | ios::app);
	Products p;
	if (!in)
	{
		cout << "ERROR. File wasn`t opened/created" << endl;
	}
	else {

		char flag;
		do {
			cout << "Enter name: ";
			cin >> p.name;
			cout << "Enter date of manufacture: ";
			cin >> date_b;
			cout << "Enter expiration date: ";
			cin >> date_e;

			convert_date(date_b, p.b_day, p.b_month, p.b_year);
			convert_date(date_e, p.e_day, p.e_month, p.e_year);
			if (!check_date(p.b_day, p.b_month, p.b_year) || !check_date(p.e_day, p.e_month, p.e_year))
			{
				cout << "Error. Wrong date" << endl;
			}
			else {
				in.write((char*)&p, sizeof(p));
			}
			cout << "Enter <Y> if you want to continue: ";
			cin >> flag;
		} while (flag == 'Y' || flag == 'y');
		in.close();
	}
}

void read(string fname)
{
	ifstream file(fname, ios::binary);

	Products p;
	while (file.read((char*)&p, sizeof(Products)))
	{
		p.Print();
	}
	
}

int date(int year, int month, int day) {
	if (month < 3)
		year--, month += 12;
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}

void expiration(string fname, string fnew1, string fnew2) {

	ifstream in(fname, ios::binary);
	if (!in)
	{
		cout << "ERROR. File wasn`t opened/created" << endl;
	}
	else {
		int total_days = 0;
		
		in.seekg(0, std::ios::end);
		size_t file_size = in.tellg();
		size_t size = file_size / sizeof(Products);

		in.seekg(0, std::ios::beg);

		Products* p = new Products[size];
		//cout << "\n\t\tAll products:" << endl;
		for (size_t i = 0; i < size; i++) {
			in.read((char*)&p[i], sizeof(Products));
			int total_days = date(p[i].e_year, p[i].e_month, p[i].e_day) - date(p[i].b_year, p[i].b_month, p[i].b_day);
			
			//cout << "Name: " << p[i].name << "\t\t Termin: " << total_days << endl;
			int y = 2023;
			int m = 3;
			int d = 24;
			if ((date(y, m, d) - date(p[i].e_year, p[i].e_month, p[i].e_day)) < 0 && total_days >= 0)
			{
				if (total_days <= 5)
				{
					ofstream out1(fnew1, ios::app | ios::binary);
					if (!out1)
					{
						cout << "File wasn`t created" << endl;
					}
					else {
						out1.write((char*)&p[i], sizeof(p[i]));
					}
					out1.close();
				}
				else
				{
					ofstream out2(fnew2, ios::app | ios::binary);
					if (!out2)
					{
						cout << "File wasn`t created" << endl;
					}
					else {
						out2.write((char*)&p[i], sizeof(p[i]));
					}
					out2.close();
				}
				
			}
		}

		//delete[] p;
	}
	in.close();

}


bool check_date(int day, int month, int year)
{
	if (day > 31 || day < 0 || month > 12 || month < 0 || year < 1800 || year > 4000)
	{
		return false;
	}
	else if (month == 2 && day > 28)
	{
		return false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void operations(int ch, string fname) 
{
	string date_e, date_b;
	string fnew1, fnew2;
	switch (ch)
	{
		case 1:
			write(fname, date_b, date_e);
			break;
		case 2:
			read(fname);
			break;
		case 3:
			cout << "Enter the name of file 1: ";
			cin >> fnew1;
			cout << "Enter the name of file 2: ";
			cin >> fnew2;
			expiration(fname, fnew1, fnew2);
			cout << "\n\t\tOUTPUT1 ( less than 5 days)\n" << endl;
			read(fnew1);
			cout << "\n\t\tOUTPUT2 ( more 5 than days)\n" << endl;
			read(fnew2);
			break;
		case 4:
			add_data(fname, date_b, date_e);
			break;
		case 5:
			cout << "Ener the name of file: ";
			cin >> fname;
			delete_file(fname);
			break;
		default:
			break;
	}
}