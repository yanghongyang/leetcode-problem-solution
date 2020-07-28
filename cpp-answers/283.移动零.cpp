/*
 * @Author: your name
 * @Date: 2020-06-09 16:09:49
 * @LastEditTime: 2020-06-09 16:11:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\283.移动零.cpp
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }
        for (; j < nums.size(); j++)
            nums[j] = 0;
    }
};
// @lc code=end
