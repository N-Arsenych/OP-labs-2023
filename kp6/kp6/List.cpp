#include"List.h"

template <typename T>
List<T>::List() { head = tail = new Node<T>; }

template <typename T>
List<T>::~List()
{
	while (head->next != nullptr)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

template<typename T>
List<T>::Iterator::Iterator(Node<T>* new_ptr) : ptr(new_ptr) {}

template<typename T>
List<T>::Iterator::Iterator() : ptr(nullptr) {}

template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& itr) { return ptr != itr.ptr; }

template<typename T>
T& List<T>::Iterator::operator*() { return ptr->next->data; }

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator temp = *this;
	ptr = ptr->next;
	return temp;
}

template<typename T>
bool List<T>::empty() { return head == tail; }

template<typename T>
void List<T>::clear()
{
	while (!empty())
	{
		erase(begin());
	}
}

template<typename T>
typename List<T>::Iterator List<T>::begin() { return Iterator(head); }

template<typename T>
typename List<T>::Iterator List<T>::end() { return Iterator(tail); }

template<typename T>
typename List<T>::Iterator List<T>::insert(Iterator pos, const T& val)
{
	Node<T>* new_node = new Node<T>(val, pos.ptr->next);
	if (pos.ptr == tail)
	{
		tail = new_node;
	}
	pos.ptr->next = new_node;
	return pos;
}

template <typename T>
typename List<T>::Iterator List<T>::erase(Iterator pos)
{
	Node<T>* to_delete = pos.ptr;
	Node<T>* prev_node = head;
	if (to_delete == head)
	{
		head = head->next;
	}
	else
	{
		while (prev_node->next != to_delete)
		{
			prev_node = prev_node->next;
		}
		prev_node->next = to_delete->next;
	}
	if (to_delete == tail)
	{
		tail = prev_node;
	}
	delete to_delete;
	return Iterator(prev_node->next);
}


template<typename T>
typename List<T>::Iterator List<T>::find(const T& val)
{
	Iterator itr = begin();
	while (itr != end()) {
		if (*itr == val) {
			return itr;
		}
		itr++;
	}
	return end();
}

template<typename T>
int List<T>::distance(Iterator first, Iterator second)
{
	int distance = 1;
	while (first != second) {
		first++;
		++distance;
	}
	return distance; 
}

