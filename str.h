#include <stdio.h>

/*
@brief ѕодсчитывает длину строки str_
@param str_: строка
@return длина строки
*/
unsigned int my_strlen(const char* str_);

/*
@brief  опирует строку src_ в строку dst_, с удалением всех элементов лежащих в строке dst_
@param dst_: конечна€ строка
@param src_: исходна€ строка
@return конечна€ строка в которую скопировали исходную
*/
char* my_strcpy(char* dst_, const char* src_);

/*
@brief ѕриписывает одну строку в другую
@param dst_: конечна€ строка
@param src_: исходна€ строка
@return конечна€ строка в которую приписали исходную
*/
char* my_strcat(char* dst_, const char* src_);

/*
@brief —равнивает строки
@param str1_: ѕерва€ строка
@param str2_: ¬трора€ строка
@return 0 если str1_ = str2_, положительное число если str1_ > str2_, отрицательное число если str1_ < str2_
*/
int my_strcmp(const char* str1_, const char* str2_);

/*
@brief »щет подстроку str2_ в строке str1_
@param str1_: —трока дл€ поиска
@param str2_: »скома€ строка
@return указатель на первое вхождение искомой строки в строке
*/
char* my_strstr(const char* str1_, const char* str2_);

/*
@brief „итает что написано в файле
@param file_: файл
@return ѕрочитанный текст записанный в строку
*/
char* fgetline(FILE* file_);