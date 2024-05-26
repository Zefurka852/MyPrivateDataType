#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct Strawberry Strawberry;

/*
@brief Создает новую структуру клубники и возвращает указатель на нее
@return указатель на новую структуру клубники
*/
Strawberry* create_strawberry();

/*
@brief Освобождает память, выделенную под структуру клубники
@param strawberry: указатель на структуру клубники
*/
void destroy_strawberry(Strawberry* strawberry);

/*
@brief Ввод информации о клубнике с клавиатуры
@param strawberry: указатель на структуру клубники
*/
void input_strawberry(Strawberry* strawberry);

/*
@brief Вывод информации о клубнике на экран
@param strawberry: указатель на структуру клубники
*/
void print_strawberry(const Strawberry* strawberry);

/*
@brief Добавляет клубнику в массив
@param strawberries: массив указателей на структуры клубники
@param num_strawberries: указатель на количество клубник в массиве
*/
void add_strawberry(Strawberry** strawberries, int* num_strawberries);

/*
@brief Выводит информацию о всех клубниках в массиве
@param strawberries: массив указателей на структуры клубники
@param num_strawberries: количество клубник в массиве
*/
void print_all_strawberries(Strawberry** strawberries, int num_strawberries);

/*
@brief Сортирует клубники по названию
@param strawberries: массив указателей на структуры клубники
@param num_strawberries: количество клубник в массиве
*/
void sort_strawberries(Strawberry** strawberries, int num_strawberries);

/*
@brief Ищет клубнику по названию
@param strawberries: массив указателей на структуры клубники
@param num_strawberries: количество клубник в массиве
@param name: название клубники для поиска
*/
void search_strawberry_by_name(Strawberry** strawberries, int num_strawberries, const char* name);

/*
@brief Удаляет клубнику из массива по цвету
@param strawberries: массив указателей на структуры клубники
@param num_strawberries: указатель на количество клубник в массиве
@param color: цвет клубники для удаления
*/
void remove_strawberry_by_color(Strawberry** strawberries, int* num_strawberries, const char* color);

#endif
