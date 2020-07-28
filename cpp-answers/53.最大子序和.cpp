/*
 * @Author: your name
 * @Date: 2020-05-30 00:48:48
 * @LastEditTime: 2020-05-30 00:50:18
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\53.最大子序和.cpp
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, smax = INT_MIN;
        for (int num : nums)
        {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return smax;
    }
};
// @lc code=end
