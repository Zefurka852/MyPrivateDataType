#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "DataType.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_STRAWBERRIES 100 // Максимальное количество клубник

int main() 
{

#ifdef _WIN32
    SetConsoleOutputCP(1251);
#endif


    int choice;
    int num_strawberries = 0;
    Strawberry* strawberries[MAX_STRAWBERRIES] = { NULL };

    do 
    {
        printf("\nМеню:\n");
        printf("1. Добавить клубнику\n");
        printf("2. Вывести информацию о всех клубниках\n");
        printf("3. Отсортировать клубники по названию\n");
        printf("4. Найти клубнику по названию\n");
        printf("5. Удалить клубнику по цвету\n");
        printf("0. Выйти\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) 
        {
        case 1:
            add_strawberry(strawberries, &num_strawberries);
            break;
        case 2:
            print_all_strawberries(strawberries, num_strawberries);
            break;
        case 3:
            sort_strawberries(strawberries, num_strawberries);
            printf("\nКлубники отсортированы по названию.\n");
            break;
        case 4:
        {
            char name[50];
            printf("\nВведите название для поиска: ");
            scanf_s("%49s", name, sizeof(name));
            search_strawberry_by_name(strawberries, num_strawberries, name);
        }
        break;
        case 5:
        {
            char color[20];
            printf("\nВведите цвет для удаления: ");
            scanf_s("%19s", color, sizeof(color));
            remove_strawberry_by_color(strawberries, &num_strawberries, color);
            printf("\nКлубники с цветом '%s' удалены.\n", color);
        }
        break;
        case 0:
            printf("Программа завершена.\n");
            break;
        default:
            printf("Некорректный ввод.\n");
            break;
        }
    } while (choice != 0);

    // Освобождение памяти, выделенной под клубники
    for (int i = 0; i < num_strawberries; i++) 
    {
        destroy_strawberry(strawberries[i]);
    }

    return 0;
}