/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;
        int remains = 0;
        while (numBottles > 0)
        {
            ans += numBottles;
            numBottles += remains;
            remains = numBottles % numExchange; //剩下的瓶子
            numBottles /= numExchange;          //能换的瓶子
        }
        return ans;
    }
};
// @lc code=end
