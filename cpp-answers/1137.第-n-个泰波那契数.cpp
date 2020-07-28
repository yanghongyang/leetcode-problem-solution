/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-01 18:48:21
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-01 18:50:06
 */
/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        int n1 = 0;
        int n2 = 1;
        int n3 = 1;
        long res = 0;
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        for (int i = 3; i <= n; i++)
        {
            res = n1 + n2 + n3;
            int tmp = res;
            n1 = n2;
            n2 = n3;
            n3 = tmp;
        }
        return res;
    }
};
// @lc code=end
