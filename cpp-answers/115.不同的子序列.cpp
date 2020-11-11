/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-12 01:36:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-12 01:50:15
 */
/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
