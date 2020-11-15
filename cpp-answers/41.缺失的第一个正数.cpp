/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-16 06:39:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-16 06:43:14
 */
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 == nums[i])
                continue; //最好的情况
            int x = nums[i];
            while (x >= 1 && x <= nums.size() && x != nums[x - 1])
            {
                swap(x, nums[x - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end
