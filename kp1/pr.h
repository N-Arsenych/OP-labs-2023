#define LEN 100
#define MAX_LINE_LEN 1000
#include<stdio.h>
#include<iostream>
#include<cstdio>										//fopen_s, fclose, fprintf, fgets, fseek
#include<cstring>										//strlen, strcpy_s, delete[]
#include<regex>

using namespace std;

void p_create(char* );									//��������� �����					
void p_delete(const char* fname);						//��������� �����
void p_read_data(const char* );							//������� � �����
void p_write_data(const char* );						//����� � ����, �� ��������� ��������� �����
void p_app_data(const char* );							//������� � ����, ��������� ���� ��������� �����
bool find_operators(const char* , smatch& );			//����� ��������� ���������, �� ��������� ������
char* replace_operators(const char* );					//���� ���������
void p_operat(const char* , const char*);				//�����, ���� �� ����� �������� �����
void switch_pointer(int , const char* , const char* );	//����, � ����� ������� �� ���� ����������� �������