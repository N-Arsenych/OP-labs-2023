#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>

using namespace std;

int choose();												//���� ��� ����������� 
void delete_file(string);									//��������� �����
void create(string);										//��������� �����
void read_data(string);										//���������� � �����
void write_data(string);									//����� � ����, �� ��������� ��������� �����									
void append_data(string );									//������� � ����, ��������� ���� ��������� �����	
bool find_operators(string , smatch );						//����� ��������� ���������, �� ��������� ������
string replace_operators(string );							//���� ���������
void operators(string, string);								//�����, ���� �� ����� �������� �����
void switch_stream(int ch, string fname, string fnew);		//����, � ����� ������� �� ���� ����������� �������