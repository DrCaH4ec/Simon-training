#include <stdlib.h>
#include <stdio.h>

#include "filling_array.h"
#include "sipmle_array.h"
#include "sorting_of_array.h"
#include "p.h"

char get_last_char()
{
    size_t capacity = 20, counter = 0;
    char *str = (char*)calloc(capacity, sizeof(char));
    char result;

    str[counter] = getchar();
    while (str[counter] != '\n')
    {
        ++counter;
        if(counter == capacity)
        {
            capacity *= 2;
            str = (char*)realloc(str, capacity * sizeof(char));
        }
        str[counter] = getchar();
    }
    printf("\nIn the string : >>%sProrgam acept first one : %c\n", str, str[0]);
    result = str[0];
    free(str);
    return result;
}

char set_param_of_array()
{
    while (1)
    {
        char user_entered_leter;

        printf("You must enter the n - num or l - leteer you array will\n");
        printf("Enter the letter: ");
        user_entered_leter = get_last_char();
        printf("\n");
        switch (user_entered_leter)
        {
        case CHOICE_OF_NUMBER:
            return user_entered_leter;
            break;
        case CHOICE_OF_LETTER:
            return user_entered_leter;
            break;
        default:
            printf("You choice : %c are incorect\n Try arain\n",  user_entered_leter);
            break;
       }
    }
}

void show_menu_to_set_sort(char *choise_of_sort)
{
    int boolean = 1;

    while (boolean)
    {
        printf("You can chose the sort");
        printf("\n b - Bubble sort\n i - Insertion sort\n c - Selection sort\n");
        printf("\nEnter your choise_of_sort : ");
        *choise_of_sort = get_last_char();
        printf("\n");
        switch (*choise_of_sort)
        {
        case CHOISE_BOBBLE_SORT :
            boolean = 0;
            break;
        case CHOISE_INSERTION_SORT :
            boolean = 0;
            break;
        case CHOISE_SELECTION_SORT :
            boolean = 0;
            break;
        default:
            boolean = 1;
            printf("You entered wrong letter : %c\n", *choise_of_sort);
            printf("Try again...\n\n");
            break;
        }
    }
    printf("Acept: choise_of_sort  = %c\n", *choise_of_sort);
    printf(" - - - - - - - - - - - \n\n");
}

void show_menu_to_set_filling(char *choise_of_filling)
{
    int boolean = 1;

    while (boolean)
    {
        printf("You can chose the type filling ");
        printf("\n c - Random char\n n - Random num\n R - Read from file\n");
        printf("\nEnter your choise_of_sort : ");
        *choise_of_filling = get_last_char();
        printf("\n");
        switch (*choise_of_filling)
        {
        case CHOISE_CHAR_TO_FILLING :
            boolean = 0;
            break;
        case CHOISE_NUM_TO_FILLING :
            boolean = 0;
            break;
        case CHOISE_FILE_TO_FILLING :
            boolean = 0;
            break;
        default:
            printf("You entered wrong letter : %c\n", *choise_of_filling);
            printf("Try again...\n\n");
            boolean = 1;
            break;
        }
    }
    printf("Acept: choise_of_filling  = %c\n", *choise_of_filling );
    printf(" - - - - - - - - - - - \n\n");
}

void show_menu_to_set_size_of_array(int *lim)
{
    while (1)
    {
        printf("Set the limits of random array\nLinits = ");
        scanf("%d", lim);
        printf("\n");
        if(*lim > 0)
            break;
    }
    printf("Acept: limits  = %d\n", *lim);
    printf(" - - - - - - - - - - - \n\n");
}

void start_dialog_to_set_param(int *lim, char *choise_of_sort, char *choise_of_filling)
{
    printf("\n\n\tProgram start\n\n");
    show_menu_to_set_sort(choise_of_sort);
    show_menu_to_set_filling(choise_of_filling);
    if(*choise_of_filling != 'R')
        show_menu_to_set_size_of_array(lim);
}

void set_memory_to_array(struct charact_array *array, int limitation)
{
    array->size = limitation;
    array->arr = malloc(sizeof(int) * limitation);
}

void set_new_memory_to_array(struct charact_array *array, int limitation)
{
    array->size = limitation;
    array->arr = (int*)realloc(array->arr, array->size * sizeof(int));
}

int main(int argc, char const *argv[])
{
    char choise_of_sort, choise_of_filling;
    int limitations = 20;
    struct charact_array *array;

    start_dialog_to_set_param(&limitations, &choise_of_sort, &choise_of_filling);
    array = malloc(sizeof(struct charact_array));
    switch (choise_of_filling)
    {
    case CHOISE_FILE_TO_FILLING :
        array->status = set_param_of_array();
        reading_array_from_file(array);
        break;
    case CHOISE_NUM_TO_FILLING :
        set_memory_to_array(array, limitations);
        filling_random_num(array);
        break;
    case CHOISE_CHAR_TO_FILLING :
        set_memory_to_array(array, limitations);
        filling_random_char(array);
        break;
    default:
        exit(SELECTION_EXCLUSION_FILLING);
        break;
    }
    write_array_to_term(array);
    switch (choise_of_sort)
    {
    case CHOISE_SELECTION_SORT :
        selection_sort(array);
        break;
    case CHOISE_INSERTION_SORT :
        insertion_sort(array);
        break;
    case CHOISE_BOBBLE_SORT :
        boble_sort(array);
        break;
    default :
        exit(SELECTION_EXCLUSION_SORT);
        break;
    }
    write_array_to_term(array);
    write_array_to_file(array);

    free(array->arr);
    free(array);
    return 0;
}
