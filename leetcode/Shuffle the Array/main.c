/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdint.h>

int* shuffle(int* nums, int nums_size, int n, int* return_size)
{
    *return_size = nums_size;
    int *result = malloc(sizeof(int) * (*return_size));
    int16_t counter = 0;
    for (int16_t i = 0; i < (*return_size);i+=2)
        result[i] = nums[counter++];
    for (int16_t i = 1; i < (*return_size);i+=2)
        result[i] = nums[counter++];
    return result;
}