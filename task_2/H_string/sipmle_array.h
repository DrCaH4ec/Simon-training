#ifndef SIMPLE_ARRAY
#define SIMPLE_ARRAY


struct charact_array
{
    int size;
    int *arr;
    char status;
};


void Set_array_status(struct charact_array *array, char new_status);
void Set_array_size(struct charact_array *array, int new_size);
void Write_array_to_term(struct charact_array *array);
void Write_array_to_file(struct charact_array *array);


#endif

