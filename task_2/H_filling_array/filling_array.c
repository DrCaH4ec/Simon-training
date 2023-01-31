#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "sipmle_array.h"
#include "filling_array.h"
#include "p.h"


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

int Determine_of_status_char(int letter, char choise_of_filling_array)
{
    switch (choise_of_filling_array)
    {
    case CHOICE_OF_NUMBER:
        if (letter >= NUMBER_OF_0 && letter <= NUMBER_OF_9)
            return 1;
        break;
    case CHOICE_OF_LETTER:
        if ((letter >= NUMBER_OF_LOWERCASE_A && letter <= NUMBER_OF_LOWERCASE_A+CHAR_SIZE) ||
            (letter >= NUMBER_OF_UPPERCASE_A && letter <= NUMBER_OF_UPPERCASE_A+CHAR_SIZE))
            return 1;
        break;
    }
    return 0;
}

void Filling_random_char(struct charact_array *array)
{
    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        rand() % 2 == 0 ?
            (array->arr[i] = (rand()% CHAR_SIZE) + NUMBER_OF_LOWERCASE_A) : 
            (array->arr[i] = (rand()% CHAR_SIZE) + NUMBER_OF_UPPERCASE_A); 
    Set_array_status(array, CHOICE_OF_LETTER);
    
}

void Filling_random_num(struct charact_array *array)
{
    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        array->arr[i] = (rand()% DIAPASON_OF_VALUE);
    Set_array_status(array, CHOICE_OF_NUMBER);
}

int Pow_ten(int a)
{
    int result = 1;
    for (int i = 1; i < a; i++)
    {
        result*=10;
    }
    return result;
}

void Reading_numbers_from_file(struct charact_array *array, int size_of_mamory, FILE *t_txt)
{
    int counter = 0;
    int boolean_taking_number = 0;
    char c = getc(t_txt);
    while (c != EOF)
    {
        if(counter == size_of_mamory)
        {
             size_of_mamory *= 2;
             Set_new_memory_to_charact_array_and_arr(array, size_of_mamory);
        }
        if(Determine_of_status_char(c, array->status))
        {
            array->arr[counter] = c;
            counter++;
            boolean_taking_number  = 1;
        }
        else
        {
            if (boolean_taking_number)
            {
                array->arr[counter] = ' ';
                counter++;
                boolean_taking_number = 0;
            }
        }
        c = getc(t_txt);
    }
    Set_new_memory_to_charact_array_and_arr(array, counter);
    
    int start_position_of_numner = 0;
    int counter_of_numbers = 0;
    for (int i = 0; i < counter+1; i++)
    {
        if (array->arr[i] == ' ')
        {
            int buf = 0;
            for (int j = start_position_of_numner; j < i ; j++)
            {
                buf += (array->arr[j] - NUMBER_OF_0) * Pow_ten(i - j);
            }
            array->arr[counter_of_numbers] = buf;
            start_position_of_numner = i + 1;
            counter_of_numbers++;
        }
    }
    Set_new_memory_to_charact_array_and_arr(array, counter_of_numbers);
       
}

void Reading_letters_from_file(struct charact_array *array, int size_of_mamory, FILE *t_txt)
{
    char c;
    int counter = 0;
    c = fgetc(t_txt);
    while (c != EOF)
    {
        if (counter == size_of_mamory)
        {
            size_of_mamory *= 2;
            Set_new_memory_to_charact_array_and_arr(array, size_of_mamory);
        }
        if (Determine_of_status_char(c, array->status))
        {
           array->arr[counter] = c;
            counter++;
        }
        c = fgetc(t_txt);
    }
    Set_new_memory_to_charact_array_and_arr(array, counter);
}

void Filling_by_reading_from_file(struct charact_array *array)
{
    
    FILE *t_txt = fopen(LINK_TO_STANDART_INPUT_FILE, "r");
    int size_of_mamory = MIN_SIZE_OF_ARRAY;

    Set_memory_to_charact_array_and_arr(array, size_of_mamory);
    switch (array->status)
    {
    case CHOICE_OF_LETTER:
        Reading_letters_from_file(array,size_of_mamory, t_txt);
        break;
    case CHOICE_OF_NUMBER:
        Reading_numbers_from_file(array,size_of_mamory, t_txt);
        break;
    default:
        exit(SELECTION_EXCLUSION_FILLING);
        break;
    }

    fclose(t_txt);
}




