/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-20 19:58:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-20 20:05:00
 */
/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution
{
public:
    int lastRemaining(int n)
    {
        return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};
// @lc code=end
