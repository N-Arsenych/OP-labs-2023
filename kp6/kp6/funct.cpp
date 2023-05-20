#include"funct.h"

//int intro()
//{
//	int n;
//	cout << "Choose what you want to do:" << endl;
//	cout << "1 - Fill the list" << endl;
//	cout << "2 - Insert an element" << endl;
//	cout << "3 - Erase an element" << endl;
//	cout << "4 - Clear the list" << endl;
//	cout << "5 - View the list" << endl;
//	cout << "6 - Check if list is empty" << endl;
//	cout << "7 - Find position of an element" << endl;
//	cout << "0 - exit" << endl;
//	cin >> n;
//	return n;
//}

template<typename T>
void fill_list(List<T>& lst)
{
	int n;
	T el;
	cout << "Choose a filling method" << endl;
	cout << "1 - manually" << endl;
	cout << "2 - random" << endl;
	cin >> n;
	int size;
	cout << "Enter how many elements do you want: ";
	cin >> size;
	if (n == 1)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i + 1 << "] : ";
			cin >> el;
			lst.insert(lst.end(), el);
		}
	}
	else if (n == 2)
	{
		for (int i = 0; i < size; i++)
		{
			el = rand() % 20 - 10;
			lst.insert(lst.end(), el);
		}
	}
	else
	{
		cout << "Error. You didn`t choose the method" << endl;
	}
}

template<typename T>
void print(List<T>& lst)
{
	for (auto i = lst.begin(); i != lst.end(); i++)
	{
		cout << *i << " ";
	}cout << endl;
}

template<typename T>
void insert_element(List<T>& lst)
{
	int ch, n;
	cout << "Choose to insert:" << endl;
	cout << "1 - to end" << endl;
	cout << "2 - to begin" << endl;
	cout << "3 - your variant" << endl;
	cin >> ch;
	T el;
	cout << "Enter the element: ";
	cin >> el;
	if (ch == 1)
	{
		lst.insert(lst.end(), el);
	}
	else if (ch == 2)
	{
		lst.insert(lst.begin(), el);
	}
	else if (ch == 3 && !lst.empty())
	{
		auto itr = lst.begin();
		cout << "Enter the position: ";
		cin >> n;
		for (int i = 1; i < n; i++)
		{
			itr++;
		}
		lst.insert(itr, el);
	}
	else
	{
		cout << "Error." << endl;
	}
}

template<typename T>
void erase_element(List<T>& lst)
{
	T el;
	cout << "Enter the element to delete: ";
	cin >> el;

	auto itr = lst.find(el);

	if (itr != lst.end()) {
		lst.erase(itr);
	}
	else {
		cout << "Element not found" << endl;
	}
}

template<typename T>
void check_empty(List<T>& lst)
{
	if (lst.empty())
	{
		cout << "Your list is empty." << endl;
	}
	else
	{
		cout << "Your list is not empty." << endl;
	}
}

template<typename T>
void find_pos(List<T>& lst)
{
	T el;
	cout << "Enter the element: ";
	cin >> el;
	auto itr = lst.find(el);
	int pos = lst.distance(lst.begin(), itr);
	cout << "The position of your element is " << pos << endl;
}


//void head()
//{
//	List<int> lst;
//	char ex;
//
//	do
//	{
//		int n = intro();
//		switch (n)
//		{
//		case(1):
//			fill_list(lst);
//			print(lst);
//			break;
//		case(2):
//			insert_element(lst);
//			print(lst);
//			break;
//		case(3):
//			erase_element(lst);
//			print(lst);
//			break;
//		case(4):
//			lst.clear();
//			break;
//		case(5):
//			print(lst);
//			break;
//		case(6):
//			check_empty(lst);
//			break;
//		case(7):
//			find_pos(lst);
//			break;
//		case(0):
//			exit(0);
//			break;
//		default:
//			break;
//		}
//		cout << "Do you want to continue? (Y/N)" << endl;
//		cin >> ex;
//
//	} while (ex == 'Y' || ex == 'y');
//
//}