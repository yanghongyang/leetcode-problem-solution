/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 22:54:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 22:57:30
 */
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
// @lc code=end
