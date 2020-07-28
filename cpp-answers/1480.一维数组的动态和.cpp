/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 22:46:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 22:46:37
 */
/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
// @lc code=end
