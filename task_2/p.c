#include <stdlib.h>
#include <stdio.h>

#include "filling_array.h"
#include "writing_to_a_file.h"
#include "sipmle_array.h"


int main()
{
    struct charact_array array;

    Set_array_size(&array, 20); 
    Filling_random_char(&array);
    Write_array_to_term(&array);
    //Printing_to_file(a, size);

    return 0;
}
