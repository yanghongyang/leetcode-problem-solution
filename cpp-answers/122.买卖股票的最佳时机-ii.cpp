/*
 * @Author: your name
 * @Date: 2020-06-05 20:53:30
 * @LastEditTime: 2020-06-05 20:55:03
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\122.买卖股票的最佳时机-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int res = 0;
        for (int t = 1; t < prices.size(); t++)
        {
            if (prices[t] - prices[t - 1] > 0)
                res += (prices[t] - prices[t - 1]);
        }
        return res;
    }
};
// @lc code=end
