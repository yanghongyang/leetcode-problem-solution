/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 16:08:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 16:12:01
 */
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; i++)
        {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
// @lc code=end
