#include <stdbool.h>
int totalFruit(int* fruits, int fruitsSize)
{
    if (fruitsSize <= 2)
        return fruitsSize;
    int fruit_counter = 0;
    int second_fruit;

    bool is_fruit_in_basket = false;    
    for (int i = 0; i < fruitsSize; i++)
    {
        is_fruit_in_basket = false;
        for (int j = i + 1;j < fruitsSize; j++)
        {
            if (fruits[j] == fruits[i] || (fruits[j] == second_fruit && is_fruit_in_basket))
            {
                if ((j - i) + 1 > fruit_counter)
                    fruit_counter = (j - i) + 1;
                continue;
            }
            if (!(is_fruit_in_basket))
            {
                second_fruit = fruits[j];
                is_fruit_in_basket = true;
                if ((j - i) + 1 > fruit_counter)
                    fruit_counter = (j - i) + 1;
            }
            else
                break;

        }
        if (fruit_counter >= fruitsSize - i - 1)
            return fruit_counter;
    }
    return fruit_counter;
}
