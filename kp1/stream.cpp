#include "sm.h"

int choose()
{
	int ch;
	cout << "Please choose what do you want to do with this file\n1 - read; 2 - repleace operators; 3 - append text; 4 - write to file; 5 - delete" << endl;
	cin >> ch;
	return ch;										//повертає значення, яке обрав користувач, щоб в подальшому передати в світч
}

void create(string fname)
{
	fstream myfile;
	myfile.open(fname);

	if (!myfile.is_open())
	{
		cout << "ERROR. File isn`t opened/created" << endl;
	}
	else
	{	
		//myfile << "int a, x, m;\na = a + 9;\nx = x + 12;\nm = m +7;\n" << endl;
		cout << "File is successfully opened/created" << endl;
	}
	myfile.close();
}


void delete_file(string fname)
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

void read_data(string fname)
{
	string s;
	ifstream myFile;
	myFile.open(fname);

	while (!myFile.eof())
	{
		getline(myFile, s);
		cout << s << endl;
	}
	myFile.close();
}

void write_data(string fname)
{
	ofstream myFile;
	myFile.open(fname, ios::out);

	cout << "Write your text. When you finish write < end > ";
	string line;
	while (1)
	{
		getline(cin, line);
		if (line == "end")
		{
			break;
		}
		myFile << line << endl;
	}
	myFile.close();
}

void append_data(string fname)
{
	ofstream myFile;
	myFile.open(fname, ios::app);

	cout << "Write your text. When you finish write < end > ";
	string line;
	while (1)
	{
		getline(cin, line);
		if (line == "end")
		{
			break;
		}
		myFile << line << endl;	
	}
	myFile.close();
}

bool find_operators(string line, smatch match)
{
	regex pattern("(\\w+)\\s*=\\s*\\1\\s*\\+\\s*(\\d+)\\s*;");       			   //шаблон для пошуку оператора
	return regex_search(line, match, pattern);
}

string replace_operators(string line)
{
	regex pattern("(\\w+)\\s*=\\s*\\1\\s*\\+\\s*(\\d+)\\s*;");
	string change = "$1 += $2;";											    //шаблон для зміни оператора
	string new_str = regex_replace(line, pattern, change);				    	//зміна оператора та збереження її у змінній new_str
	return new_str;
}

void operators(string fname, string fnew)
{
	ifstream input_file;
	input_file.open(fname);
	string line, last_line;
	fstream output_file;
	output_file.open(fnew, ios::out);
	string new_str, change;
	int count = 0;
		
		
	while (getline(input_file, line)) {											//зчитування тексту з файла по рядках
		smatch match;
		if (find_operators(line, match)) {										//перевірка чи знайдений оператор
			new_str = replace_operators(line);									//зміна оператора
			count++;	
			last_line = new_str;												//зберігаємо останній рядок
			output_file << new_str << endl;										//збереження зміненого рядка у вихідному файлі
		}
		else {
			output_file << line << endl;								         //якщо в прочитаному рядку не було потрібного нам оператора,
		}							    								         // то записуємо цей рядок у вихідний файл, не змінюючи нічого
	}

	if (count > 0) {															 //перевіряємо чи було змінено хоч один оператор
		string count_str = to_string(count);								 //перетворення значення count у string
		new_str = regex_replace(new_str, regex("\\d+"), count_str);				 //зміна останнього зміненого оператора
		input_file.clear();														 //очищує прапорці помилок для файлу введення
		input_file.seekg(-(static_cast<int>(last_line.length()) + 1), ios::end); //переміщує покажчик позиції для файлу введення на кінець файлу
		getline(input_file, line);												 			
		output_file.seekp(-(static_cast<int>(line.length()+2) + 1), ios::end);   //переміщує покажчик на початок line
		output_file << new_str << endl;
	}


	//cout << "\ncounter: " << count << "\n";
	input_file.close();
	output_file.close();
}



void switch_stream(int ch, string fname, string fnew)
{
	switch (ch)
	{
	case 1:
		read_data(fname);
		break;
	case 2:
		cout << "\n\tINPUT FILE\n" << endl;
		read_data(fname);
		operators(fname, fnew);
		cout << "\n\tOUTPUT FILE\n" << endl;
		read_data(fnew);
		break;
	case 3:
		append_data(fname);
		break;
	case 4:
		write_data(fname);
		break;
	case 5:
		cout << "Enter the name of your file: ";
		cin >> fname;
		delete_file(fname);
		break;

	default:
		break;
	}

}
