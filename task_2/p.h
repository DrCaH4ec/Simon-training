#ifndef P
#define P

#define CHOISE_CHAR_TO_FILLING 'c'
#define CHOISE_NUM_TO_FILLING 'n'
#define CHOISE_FILE_TO_FILLING 'R'
#define CHOISE_SELECTION_SORT 's'
#define CHOISE_INSERTION_SORT 'i'
#define CHOISE_BOBBLE_SORT 'b'
#define CHOICE_OF_LETTER 'l'
#define CHOICE_OF_NUMBER 'n'
#define SELECTION_EXCLUSION_SORT 1
#define SELECTION_EXCLUSION_FILLING 2

void set_memory_to_array(struct charact_array *array, int limitation);
void set_new_memory_to_array(struct charact_array *array, int limitation);

#endif
