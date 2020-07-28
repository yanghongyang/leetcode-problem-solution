/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-01 17:32:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-01 17:40:05
 */
/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
