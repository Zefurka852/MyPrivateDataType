#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "DataType.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_STRAWBERRIES 100 // ������������ ���������� �������

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
        printf("\n����:\n");
        printf("1. �������� ��������\n");
        printf("2. ������� ���������� � ���� ���������\n");
        printf("3. ������������� �������� �� ��������\n");
        printf("4. ����� �������� �� ��������\n");
        printf("5. ������� �������� �� �����\n");
        printf("0. �����\n");
        printf("�������� ��������: ");
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
            printf("\n�������� ������������� �� ��������.\n");
            break;
        case 4:
        {
            char name[50];
            printf("\n������� �������� ��� ������: ");
            scanf_s("%49s", name, sizeof(name));
            search_strawberry_by_name(strawberries, num_strawberries, name);
        }
        break;
        case 5:
        {
            char color[20];
            printf("\n������� ���� ��� ��������: ");
            scanf_s("%19s", color, sizeof(color));
            remove_strawberry_by_color(strawberries, &num_strawberries, color);
            printf("\n�������� � ������ '%s' �������.\n", color);
        }
        break;
        case 0:
            printf("��������� ���������.\n");
            break;
        default:
            printf("������������ ����.\n");
            break;
        }
    } while (choice != 0);

    // ������������ ������, ���������� ��� ��������
    for (int i = 0; i < num_strawberries; i++) 
    {
        destroy_strawberry(strawberries[i]);
    }

    return 0;
}