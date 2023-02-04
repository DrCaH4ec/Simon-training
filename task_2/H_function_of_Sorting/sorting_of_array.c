#include <stdlib.h>
#include <stdio.h>

#include "sipmle_array.h"
#include "sorting_of_array.h"

void Swap_array_numbers(int *number_1, int *number_2)
{
    int buf = *number_1;
    *number_1 = *number_2;
    *number_2 = buf;  
}

void Sorting_by_boble(struct charact_array *array) 
{
    printf("\n\nSorting_by_boble --- start\n\n");
    for (int i = 0; i < array->size - 1; i++)
    {
        int buf;
        if (array->arr[i] > array->arr[i+1])
        {
            Swap_array_numbers(&array->arr[i], &array->arr[i+1]);
            i = -1;
        }
    }
}

void Sorting_by_insertion(struct charact_array *array) 
{
    printf("\n\nSorting_by_insertion --- start\n\n");
        int element,j;
        for (int i = 0; i < array->size; i++)
        {
            element = array->arr[i];
            for (j = i - 1; j >= 0 && array->arr[j] > element; j--)
                array->arr[j+1] = array->arr[j];
            array->arr[j+1] = element;
        }
}

void Sorting_by_selection(struct charact_array *array) 
{
    printf("\n\nSorting_by_selection --- start\n\n");
    int min_index;
    for (int i = 0; i < array->size; i++)
        for (int j = i + 1; j < array->size; j++)
            if (array->arr[i] > array->arr[j])
                Swap_array_numbers(&array->arr[i],&array->arr[i]); 
}

int Cheking_for_sorted(struct charact_array *array)
{
    for (int i = 0; i < array->size - 1; i++)
        if (array->arr[i] > array->arr[i+1])
            return 1;
    return 0;
}