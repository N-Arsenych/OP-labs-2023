#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>

using namespace std;

int choose();												//меню для користувача 
void delete_file(string);									//видалення файлу
void create(string);										//створення файлу
void read_data(string);										//зчитування з файлу
void write_data(string);									//запис у файл, не зберігаючи попередній текст									
void append_data(string );									//дозапис у файл, зберігаючи весь попередній текст	
bool find_operators(string , smatch );						//пошук операторів присвоєння, які необхідно змінити
string replace_operators(string );							//зміна операторів
void operators(string, string);								//пошук, зміна та запис зміненого файла
void switch_stream(int ch, string fname, string fnew);		//світч, у якому присутні всі вище перераховані функції