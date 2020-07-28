/*
 * @Author: your name
 * @Date: 2020-06-05 20:49:00
 * @LastEditTime: 2020-06-05 20:50:17
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\121.买卖股票的最佳时机.cpp
 */
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};
// @lc code=end
