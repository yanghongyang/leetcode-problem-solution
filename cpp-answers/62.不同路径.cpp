/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-16 10:34:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-16 10:38:22
 */
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    //普通做法
    /* int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    } */
    int uniquePaths(int m, int n)
    {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};
// @lc code=end
