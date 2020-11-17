/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-17 20:15:12
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-17 20:29:42
 */
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution
{
public:
    int minSteps(int n)
    {
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                n /= i;
                cnt += i;
            }
        }
        return cnt;
    }
};
// @lc code=end
