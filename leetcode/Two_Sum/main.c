/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int *result  = malloc(sizeof(int) * *returnSize );
    int border_num; // border - meaning an extremely number of nums[]
    int index_left_border = 0 ; // index of smaler num
    int index_right_border = 0 ; //  index of smaler num
    int buf = nums[0]; 

    for (int i = 0; i  < numsSize; i++ )
            if (buf > nums[i])
            {
                buf = nums[i];
                index_right_border = i;
            }
    border_num  = target - buf;

    while (1)
    {
        for (int i = 0; i  < numsSize; i++ )
        {
            if (nums[i] == border_num && index_right_border != i)
            {
                result[0] = i;
                result[1] = index_right_border;
                return result;
            }
            if (nums[i] < border_num)
                if (buf < nums[i])
                {
                    buf = nums[i];
                    index_left_border = i;
                }
        }
        border_num = target - buf;
        for (int i = 0; i  < numsSize; i++ )
        {
            if (nums[i] == border_num && index_left_border != i)
            {
                result[0] = i;
                result[1] = index_left_border;
                return result;
            }
            if (nums[i] > border_num)
                if (buf > nums[i])
                {
                    buf = nums[i];
                    index_right_border = i;
                }
        }
        border_num = target - buf;
    }
}
