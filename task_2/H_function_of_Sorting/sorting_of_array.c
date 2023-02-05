#include <stdlib.h>
#include <stdio.h>

#include "sipmle_array.h"
#include "sorting_of_array.h"

void swap_array_numbers(int *number_1, int *number_2)
{
    int buf = *number_1;
    *number_1 = *number_2;
    *number_2 = buf;  
}

void boble_sort(struct charact_array *array) 
{
    printf("\n\nboble_sort --- start\n\n");
    for (int i = 0; i < array->size - 1; i++)
    {
        int buf;
        if (array->arr[i] > array->arr[i+1])
        {
            swap_array_numbers(&array->arr[i], &array->arr[i+1]);
            i = -1;
        }
    }
}

void insertion_sort(struct charact_array *array) 
{
    printf("\n\ninsertion_sort --- start\n\n");
        int element,j;
        for (int i = 0; i < array->size; i++)
        {
            element = array->arr[i];
            for (j = i - 1; j >= 0 && array->arr[j] > element; j--)
                array->arr[j+1] = array->arr[j];
            array->arr[j+1] = element;
        }
}

void selection_sort(struct charact_array *array) 
{
    printf("\n\nselection_sort --- start\n\n");
    int min_index;
    for (int i = 0; i < array->size; i++)
        for (int j = i + 1; j < array->size; j++)
            if (array->arr[i] > array->arr[j])
                swap_array_numbers(&array->arr[i],&array->arr[i]); 
}

int cheking_for_sorted(struct charact_array *array)
{
    for (int i = 0; i < array->size - 1; i++)
        if (array->arr[i] > array->arr[i+1])
            return 1;
    return 0;
}
