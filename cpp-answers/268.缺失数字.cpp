/*
 * @Author: your name
 * @Date: 2020-06-13 19:20:43
 * @LastEditTime: 2020-06-13 19:24:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\268.缺失数字.cpp
 */
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int res = nums.size();
        for (int i = 0; i < n; i++)
        {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end
