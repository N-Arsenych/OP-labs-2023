#include"funct.h"

template<typename T>
void fill_list(List<T>& lst)
{
	T el;
	int size;
	cout << "Enter how many elements do you want: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> el;
		lst.insert(lst.end(), el);
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

template<typename T>
void find_element(List<T>& lst)
{
	int pos;
	cout << "Enter the position: ";
	cin >> pos;

	auto itr = lst.begin();
	for (int i = 1; i < pos; i++)
	{
		itr++;
	}
	cout << *itr << endl;
}

template<typename T>
void is_end(List<T>& lst)
{
	std::size_t count = 0;
	auto itr = lst.begin();
	while (itr != lst.end())
	{
		++itr;
		++count;
	}
	cout << "The last element is: " << *itr << endl;
	cout << "This list has " << count << " elements" << endl;
}
