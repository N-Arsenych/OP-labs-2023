#include"List.h"
#include"List.cpp"
#include"funct.h"
#include"funct.cpp"

int menu()
{
	int n;
	cout << "Choose what you want to do:" << endl;
	cout << "1 - Fill the list" << endl;
	cout << "2 - Insert an element" << endl;
	cout << "3 - Erase an element" << endl;
	cout << "4 - Clear the list" << endl;
	cout << "5 - View the list" << endl;
	cout << "6 - Check if list is empty" << endl;
	cout << "7 - Find position of an element" << endl;
	cout << "0 - exit" << endl;
	cin >> n;
	return n;
}

template<typename T>
void head(List<T> lst)
{
	char ex;
	int n;
	do
	{
		n = menu();
		switch (n)
		{
		case(1):
			fill_list(lst);
			print(lst);
			break;
		case(2):
			insert_element(lst);
			print(lst);
			break;
		case(3):
			erase_element(lst);
			print(lst);
			break;
		case(4):
			lst.clear();
			break;
		case(5):
			print(lst);
			break;
		case(6):
			check_empty(lst);
			break;
		case(7):
			find_pos(lst);
			break;
		case(0):
			exit(0);
			break;
		default:
			break;
		}
		cout << "Do you want to continue? (Y/N)" << endl;
		cin >> ex;

	} while (ex == 'Y' || ex == 'y');
}

int main()
{
	srand(time(NULL));
	int n;

	List<int> lst;
	head(lst);
	
	return 0;
}
