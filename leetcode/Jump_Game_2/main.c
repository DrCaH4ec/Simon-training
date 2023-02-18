/*I have  a question.
 You can see in the fonction find_short_way (...) <- long list of arguments.
 Its correct or i must create structture or its OK ?*/

int find_short_way(int* nums,int nums_size, int index, int step_counter)
{
    for ( int i = 0; i < index; i++)
        if (i + nums[i] >= index)
            return find_short_way(nums, nums_size, i, ++step_counter);
    return step_counter;
}
int jump(int* nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    return find_short_way(nums, numsSize, numsSize - 1, 0);
}
