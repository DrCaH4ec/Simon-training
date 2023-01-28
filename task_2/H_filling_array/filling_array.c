#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "sipmle_array.h"
#include "filling_array.h"


#define CHAR_SIZE  26
#define NUNBER_OF_UPPERCASE_A 65
#define NUMBER_OF_LOWERCASE_A 97
#define DIAPASON_OF_VALUE  100


void Filling_random_char(struct charact_array *array)
{
    int arr_char[array->size];

    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        rand() % 2 == 0 ?
            (arr_char[i] = (rand()% CHAR_SIZE) + NUMBER_OF_LOWERCASE_A) : 
            (arr_char[i] = (rand()% CHAR_SIZE) + NUNBER_OF_UPPERCASE_A); 
    Set_array(array, arr_char, 1);
}

void Filling_random_num(struct charact_array *array)
{
    int arr_int[array->size];

    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        arr_int[i] = (rand()% DIAPASON_OF_VALUE);
    Set_array(array, arr_int, 0);
}

void Read_array_from_file()
{
    
}


