#ifndef FILLING_ARRAY
#define FILLING_ARRAY

#include "sipmle_array.h"

#define CHAR_SIZE  26
#define NUMBER_OF_UPPERCASE_A 65
#define NUMBER_OF_LOWERCASE_A 97
#define NUMBER_OF_0 48
#define NUMBER_OF_9 57
#define DIAPASON_OF_VALUE  100
#define LINK_TO_STANDART_INPUT_FILE "/Users/simon/DRS_White_man/Simon-training/task_2/Input.txt"
#define CHOICE_OF_LETTER 'l'
#define CHOICE_OF_NUMBER 'n'
#define CHOICE_OF_IMPRECISE 'I'
#define MIN_SIZE_OF_ARRAY 20
#define SELECTION_EXCLUSION_FILLING 2

void Filling_random_char(struct charact_array *array);
void Filling_random_num(struct charact_array *array);
void Filling_by_reading_from_file(struct charact_array *array);

#endif

