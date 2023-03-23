#define LEN 100
#define MAX_LINE_LEN 1000
#include<stdio.h>
#include<iostream>
#include<cstdio>										//fopen_s, fclose, fprintf, fgets, fseek
#include<cstring>										//strlen, strcpy_s, delete[]
#include<regex>

using namespace std;

void p_create(char* );									//створення файлу					
void p_delete(const char* fname);						//видалення файлу
void p_read_data(const char* );							//читання з файлу
void p_write_data(const char* );						//запис у файл, не зберігаючи попередній текст
void p_app_data(const char* );							//дозапис у файл, зберігаючи весь попередній текст
bool find_operators(const char* , smatch& );			//пошук операторів присвоєння, які необхідно змінити
char* replace_operators(const char* );					//зміна операторів
void p_operat(const char* , const char*);				//пошук, зміна та запис зміненого файла
void switch_pointer(int , const char* , const char* );	//світч, у якому присутні всі вище перераховані функції