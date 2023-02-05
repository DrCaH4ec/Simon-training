#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "sipmle_array.h"
#include "filling_array.h"
#include "p.h"

int determine_of_status_char(int letter, char choise_of_filling_array)
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

void filling_random_char(struct charact_array *array)
{
    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        rand() % 2 == 0 ?
            (array->arr[i] = (rand()% CHAR_SIZE) + NUMBER_OF_LOWERCASE_A) : 
            (array->arr[i] = (rand()% CHAR_SIZE) + NUMBER_OF_UPPERCASE_A); 
    set_array_status(array, CHOICE_OF_LETTER);
    
}

void filling_random_num(struct charact_array *array)
{
    srand(time(NULL));
    for (int i = 0; i < array->size; i++)
        array->arr[i] = (rand()% DIAPASON_OF_VALUE);
    set_array_status(array, CHOICE_OF_NUMBER);
}

void reading_numbers(struct charact_array *array, int size_of_mamory, FILE *t_txt)
{
    int counter = 0;
    int boolean_taking_number = 0;
    char c = getc(t_txt);
    while (c != EOF)
    {
        if(counter == size_of_mamory)
        {
             size_of_mamory *= 2;
             set_new_memory_to_array(array, size_of_mamory);
        }
        if(determine_of_status_char(c, array->status))
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
    set_new_memory_to_array(array, counter);
    
    int start_position_of_numner = 0;
    int counter_of_numbers = 0;
    for (int i = 0; i < counter+1; i++)
    {
        if (array->arr[i] == ' ')
        {
            int buf = 0;
            for (int j = start_position_of_numner; j < i ; j++)
            {
                buf += (array->arr[j] - NUMBER_OF_0) * Pow(10,i - j);
            }
            array->arr[counter_of_numbers] = buf;
            start_position_of_numner = i + 1;
            counter_of_numbers++;
        }
    }
    set_new_memory_to_array(array, counter_of_numbers);
}

void reading_letters(struct charact_array *array, int size_of_mamory, FILE *t_txt)
{
    char c;
    int counter = 0;
    c = fgetc(t_txt);
    while (c != EOF)
    {
        if (counter == size_of_mamory)
        {
            size_of_mamory *= 2;
            set_new_memory_to_array(array, size_of_mamory);
        }
        if (determine_of_status_char(c, array->status))
        {
           array->arr[counter] = c;
            counter++;
        }
        c = fgetc(t_txt);
    }
    set_new_memory_to_array(array, counter);
}

void reading_array_from_file(struct charact_array *array)
{
    
    FILE *t_txt = fopen(LINK_TO_STANDART_INPUT_FILE, "r");
    int size_of_mamory = MIN_SIZE_OF_ARRAY;

    set_memory_to_array(array, size_of_mamory);
    switch (array->status)
    {
    case CHOICE_OF_LETTER:
        reading_letters(array,size_of_mamory, t_txt);
        break;
    case CHOICE_OF_NUMBER:
        reading_numbers(array,size_of_mamory, t_txt);
        break;
    default:
        exit(SELECTION_EXCLUSION_FILLING);
        break;
    }

    fclose(t_txt);
}
