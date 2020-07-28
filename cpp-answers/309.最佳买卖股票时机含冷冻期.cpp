/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-10 21:17:30
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-10 21:55:59
 */
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        //f[i][0]: 手上持有股票的最大收益
        //f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        //f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};
// @lc code=end
