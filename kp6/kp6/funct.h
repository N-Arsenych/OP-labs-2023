#pragma once
#include"List.h"
#include<ctime>

using namespace std;

template<typename T>
void fill_list(List<T>&);
template<typename T>
void print(List<T>&);
template<typename T>
void insert_element(List<T>& );
template<typename T>
void erase_element(List<T>& );
template<typename T>
void check_empty(List<T>& );
template<typename T>
void find_pos(List<T>& lst);
template<typename T>
void find_element(List<T>& lst);