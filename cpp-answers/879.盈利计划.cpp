/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-31 15:54:24
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-31 17:38:21
 */
/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution
{
public:
    //dp[i][j][k]表示从前i个案子中，作案人数为j时，获得的利润为k时的方案数。这前i个案子可以做，也可以不做
    //首先初始化状态dp[0][0][0]=1，即在前0个案子中，作案人数为0，所得利润为0的时候，方案数为1（什么都不干）
    //状态方程为：
    //1. dp[i][j][k] = dp[i][j][k] + dp[i - 1][j - group[i]][k - profit[i]] //如果做了第i个案子，那么总方案数=做第i个案子的方案数+前i-1个案子的总方案数
    //2. dp[i][j][k] = dp[i - 1][j][k]  //如果因为其他原因（人不够/利润<profit[i]），则不能选第i个案子，此时的总方案数=做前i-1个案子的总方案数
    //所求的结果即为：在前i个案子中，所得利润>=minProfit且作案人数<=n时候的方案总和
    //没有优化的话会TLE，如下
    /*     int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int mod = 1000000007;
        int sum = 0;             //做完所有案子得总利润
        int gnum = group.size(); //案子总数
        for (int i = 0; i < profit.size(); i++)
        {
            sum += profit[i];
        }
        vector<vector<vector<int>>> dp(gnum + 1, vector<vector<int>>(n + 1, vector<int>(sum + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= gnum; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= sum; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
            for (int j = n; j >= group[i - 1]; j--)
            {
                for (int k = sum; k >= profit[i - 1]; k--)
                {
                    dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j - group[i - 1]][k - profit[i - 1]] % mod) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= n; j++)
        {
            for (int k = minProfit; k <= sum; k++)
            {
                res = (res + dp[gnum][j][k]) % mod;
            }
        }
        return res;
    } */
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int mod = 1000000007;
        int gnum = group.size(); //案子总数
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= gnum; i++)
        {
            for (int j = n; j >= group[i - 1]; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                {
                    dp[j][k] = (dp[j][k] % mod + dp[j - group[i - 1]][max(k - profit[i - 1], 0)] % mod) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= n; j++)
        {
            res = (res + dp[j][minProfit]) % mod;
        }
        return res;
    }
};
// @lc code=end
