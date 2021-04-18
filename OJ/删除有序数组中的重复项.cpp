/*
给你一个有序数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。
输入：nums = [1,1,2] 输出：2, nums = [1,2]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
输入：nums = [0,0,1,1,1,2,2,3,3,4] 输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
*/

int removeDuplicates(vector<int>& nums)
{
    // if (nums.empty())
    // {
    //     return 0;
    // }

    // int newLen = 1;
    // int numLen = nums.size();

    // int i = 0, j = 0; 
    // while (j < numLen)
    // {
    //     if (nums[i] == nums[j])
    //     {
    //         ++j;
    //     }
    //     else
    //     {
    //         nums[++i] = nums[j];
    //         ++newLen;
    //     }
    // }

    // return newLen;

    int n = nums.size();
    if (0 == n)
    {
        return 0;
    }

    int fast = 1, slow = 1;
    while (fast < n)
     {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }

    return slow;
}
