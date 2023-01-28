#include <stdlib.h>
#include <stdio.h>

#include "writing_to_a_file.h"

void Printing_to_file(char *a, int size)
{
    char g[] = "/Users/simon/DRS_White_man/Simon-training/task_2/H_Writing_to_a_file/ttt.txt";
    FILE *file = fopen(g, "w");
    for (int  i = 0; i < size; i++)
        fprintf(file, "%c", a[i]);
    fclose(file);
}

