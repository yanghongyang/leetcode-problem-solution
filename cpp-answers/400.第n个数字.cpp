/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-20 20:07:09
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-20 20:13:19
 */
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 */

// @lc code=start
class Solution
{
public:
    int find(int n, int p)
    {
        if (n > 9 * p * pow(10, p - 1))
        {
            return find(n - 9 * p * pow(10, p - 1), p + 1);
        }
        else
        {
            int x = (n - 1) / p + pow(10, p - 1);
            int k = (n - 1) % p;

            return (x / (int)pow(10, p - k - 1)) % 10;
        }
    }
    int findNthDigit(int n)
    {
        return find(n, 1);
    }
};
// @lc code=end
