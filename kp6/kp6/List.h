#pragma once
#include<iostream>

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node() : next(nullptr) {}
	Node(const T& val, Node<T>* ptr = nullptr) : data(val), next(ptr) {}
};

template<typename T>
class List
{
	Node<T>* head;
	Node<T>* tail;
public:
	List();
	~List();

	class Iterator
	{
		friend class List;
	private:
		Node<T>* ptr;
		Iterator(Node<T>* new_ptr);
	public:
		Iterator();
		bool operator !=(const Iterator& itr);
		T& operator*();
		Iterator operator++(int);
	};

	Iterator begin();
	Iterator end();
	Iterator insert(Iterator pos, const T& val);
	Iterator erase(Iterator pos);
	Iterator find(const T& val);

	int distance(Iterator first, Iterator second);

	bool empty();
	void clear();
	T find_end()
	{
		return tail->data;
	}
};


