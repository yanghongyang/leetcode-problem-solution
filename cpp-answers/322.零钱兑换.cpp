/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-27 23:45:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-27 23:58:08
 */
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    //动态规划，滚动数组maybe?
    /*     int coinChange(vector<int> &coins, int amount)
    {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    } */
    void coinChanget(vector<int> &coins, int amount, int c_index, int count, int &ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size())
            return;
        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        { //k = amount / coins[c_index]   计算最大能投几个硬币
            //acount - k * coins[c_index]   减去扔了k歌硬币
            //count + k                     加k个硬币
            coinChanget(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        sort(coins.rbegin(), coins.rend()); //从大到小排序可以直接使用反向迭代器
        int ans = INT_MAX;
        coinChanget(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
