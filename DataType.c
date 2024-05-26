#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataType.h"
#include "str.h"

#define MAX_STRAWBERRIES 100

struct Strawberry 
{
    char variety[50];
    char color[20];
    int weight;
};

Strawberry* create_strawberry(const char* variety, const char* color, int weight) 
{
    Strawberry* strawberry = (Strawberry*)malloc(sizeof(Strawberry));
    if (strawberry != NULL) 
    {
        my_strcpy(strawberry->variety, sizeof(strawberry->variety), variety);
        my_strcpy(strawberry->color, sizeof(strawberry->color), color);
        strawberry->weight = weight;
    }
    return strawberry;
}

void destroy_strawberry(Strawberry* strawberry) 
{
    if (strawberry != NULL) 
    {
        free(strawberry);
    }
}

void print_strawberry(const Strawberry* strawberry) 
{
    if (strawberry != NULL) 
    {
        printf("Название сорта: %s\n", strawberry->variety);
        printf("Цвет: %s\n", strawberry->color);
        printf("Вес в граммах: %d\n", strawberry->weight);
    }
}

void input_strawberry(Strawberry* strawberry) 
{
    if (strawberry != NULL) {
        printf("Введите название сорта: ");
        scanf_s("%49s", strawberry->variety, sizeof(strawberry->variety));
        printf("Введите цвет: ");
        scanf_s("%19s", strawberry->color, sizeof(strawberry->color));
        printf("Введите вес в граммах: ");
        scanf_s("%d", &strawberry->weight);
    }
}

void add_strawberry(Strawberry** strawberries, int* num_strawberries) 
{
    if (*num_strawberries < MAX_STRAWBERRIES) 
    {
        strawberries[*num_strawberries] = (Strawberry*)malloc(sizeof(Strawberry));
        if (strawberries[*num_strawberries] != NULL) 
        {
            input_strawberry(strawberries[*num_strawberries]);
            (*num_strawberries)++;
        }
        else 
        {
            printf("Ошибка: не удалось выделить память для новой клубники.\n");
        }
    }
    else 
    {
        printf("Превышено максимальное количество клубник.\n");
    }
}

void sort_strawberries(Strawberry** strawberries, int num_strawberries) 
{
    int i, j;
    Strawberry* temp;

    for (i = 0; i < num_strawberries - 1; i++) 
    {
        for (j = 0; j < num_strawberries - i - 1; j++) 
        {
            if (my_strcmp(strawberries[j]->variety, strawberries[j + 1]->variety) > 0) 
            {
                temp = strawberries[j];
                strawberries[j] = strawberries[j + 1];
                strawberries[j + 1] = temp;
            }
        }
    }
}

void search_strawberry_by_name(Strawberry** strawberries, int num_strawberries, const char* name) 
{
    int i, found = 0;
    for (i = 0; i < num_strawberries; i++) 
    {
        if (my_strcmp(strawberries[i]->variety, name) == 0) 
        {
            print_strawberry(strawberries[i]);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("Клубника с названием '%s' не найдена.\n", name);
    }
}

void remove_strawberry_by_color(Strawberry** strawberries, int* num_strawberries, const char* color) 
{
    int i, j = 0;
    for (i = 0; i < *num_strawberries; i++) {
        if (my_strcmp(strawberries[i]->color, color) != 0) 
        {
            strawberries[j] = strawberries[i];
            j++;
        }
        else 
        {
            destroy_strawberry(strawberries[i]);
        }
    }
    *num_strawberries = j;
}

void print_all_strawberries(Strawberry** strawberries, int num_strawberries) 
{
    for (int i = 0; i < num_strawberries; i++) 
    {
        printf("\nКлубника %d:\n", i + 1);
        print_strawberry(strawberries[i]);
    }
}