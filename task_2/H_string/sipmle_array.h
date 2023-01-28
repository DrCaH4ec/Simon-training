#ifndef SIMPLE_ARRAY
#define SIMPLE_ARRAY


struct charact_array
{
    int size;
    int *arr;
    unsigned status;
};

void Set_array(struct charact_array *array, int *new_arr, unsigned new_status);
void Set_array_size(struct charact_array *array, int new_size);
void Write_array_to_term(struct charact_array *array);


#endif

