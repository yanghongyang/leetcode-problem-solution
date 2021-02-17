/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX)); // k+2 是因为算上起点和终点总共有 k+2 个点
        for (int i = 0; i <= k + 1; i++)
        {
            dp[i][src] = 0; //途径任意一点到达源点的最小值都是 0 （源点不用走）
        }
        for (int i = 1; i <= k + 1; i++)
        {
            for (auto &f : flights)
            {
                int u = f[0];
                int v = f[1];
                int w = f[2];

                if (dp[i - 1][u] != INT_MAX)
                {
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
                }
            }
        }
        return (dp[k + 1][dst] == INT_MAX) ? -1 : dp[k + 1][dst];
    }
};
// @lc code=end
