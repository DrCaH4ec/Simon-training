#include <stdlib.h>
#include <stdio.h>

#include "sipmle_array.h"

#define LINK_TO_STANDART_OUTPUT_FILE "/Users/simon/DRS_White_man/Simon-training/task_2/Output.txt"
#define CHOICE_OF_LETTER 'l'
#define CHOICE_OF_NUMBER 'n'

void Set_array_status(struct charact_array *array, char new_status)
{
    array->status = new_status;
}
void Set_array_size(struct charact_array *array, int new_size)
{
    array->size = new_size;
}

void Write_array_to_term(struct charact_array *array)
{
    printf("Array now is :\n");
    for (int i = 0; i < array->size; i++)
        array->status == CHOICE_OF_LETTER ?  
                        printf("%c ", array->arr[i]) : 
                        printf("%d ", array->arr[i]);
    printf("\n");
}

void Write_array_to_file(struct charact_array *array)
{
    FILE *file_txt = fopen(LINK_TO_STANDART_OUTPUT_FILE, "w");
    for (int  i = 0; i < array->size; i++)
        array->status == CHOICE_OF_LETTER ?  
                        fprintf(file_txt, "%c ", array->arr[i]) :
                        fprintf(file_txt, "%d ", array->arr[i]);
}


