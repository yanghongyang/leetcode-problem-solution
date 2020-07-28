/*
 * @Author: your name
 * @Date: 2020-05-28 22:41:49
 * @LastEditTime: 2020-05-28 22:50:04
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\26.删除排序数组中的重复项.cpp
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int n : nums)
        {
            if (!i || n > nums[i - 1])
                nums[i++] = n;
        }
        return i;
    }
};
// @lc code=end
