/*
 * @Author: your name
 * @Date: 2020-06-05 21:00:58
 * @LastEditTime: 2020-06-05 21:02:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\136.只出现一次的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int t = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            t ^= nums[i];
        }
        return t;
    }
};
// @lc code=end
