#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct Strawberry Strawberry;

/*
@brief ������� ����� ��������� �������� � ���������� ��������� �� ���
@return ��������� �� ����� ��������� ��������
*/
Strawberry* create_strawberry();

/*
@brief ����������� ������, ���������� ��� ��������� ��������
@param strawberry: ��������� �� ��������� ��������
*/
void destroy_strawberry(Strawberry* strawberry);

/*
@brief ���� ���������� � �������� � ����������
@param strawberry: ��������� �� ��������� ��������
*/
void input_strawberry(Strawberry* strawberry);

/*
@brief ����� ���������� � �������� �� �����
@param strawberry: ��������� �� ��������� ��������
*/
void print_strawberry(const Strawberry* strawberry);

/*
@brief ��������� �������� � ������
@param strawberries: ������ ���������� �� ��������� ��������
@param num_strawberries: ��������� �� ���������� ������� � �������
*/
void add_strawberry(Strawberry** strawberries, int* num_strawberries);

/*
@brief ������� ���������� � ���� ��������� � �������
@param strawberries: ������ ���������� �� ��������� ��������
@param num_strawberries: ���������� ������� � �������
*/
void print_all_strawberries(Strawberry** strawberries, int num_strawberries);

/*
@brief ��������� �������� �� ��������
@param strawberries: ������ ���������� �� ��������� ��������
@param num_strawberries: ���������� ������� � �������
*/
void sort_strawberries(Strawberry** strawberries, int num_strawberries);

/*
@brief ���� �������� �� ��������
@param strawberries: ������ ���������� �� ��������� ��������
@param num_strawberries: ���������� ������� � �������
@param name: �������� �������� ��� ������
*/
void search_strawberry_by_name(Strawberry** strawberries, int num_strawberries, const char* name);

/*
@brief ������� �������� �� ������� �� �����
@param strawberries: ������ ���������� �� ��������� ��������
@param num_strawberries: ��������� �� ���������� ������� � �������
@param color: ���� �������� ��� ��������
*/
void remove_strawberry_by_color(Strawberry** strawberries, int* num_strawberries, const char* color);

#endif
