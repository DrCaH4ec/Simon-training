#include <stdlib.h>
#include <stdio.h>

#include "sipmle_array.h"

void Set_array(struct charact_array *array, int *new_arr, unsigned new_status)
{
    array->arr = new_arr;
    array->status = new_status;
}

void Set_array_size(struct charact_array *array, int new_size)
{ 
    array->size = new_size;
}

void Write_array_to_term(struct charact_array *array)
{
    printf("array is : \n");
    for (int i = 0; i < array->size; i++)
        array->status ?  
                    printf("%c ", (char)array->arr[i]) : 
                    printf("%c ", array->arr[i]);
}
