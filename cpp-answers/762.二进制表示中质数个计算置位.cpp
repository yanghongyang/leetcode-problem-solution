/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-16 23:58:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 00:01:01
 */
/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution
{
public:
    int countPrimeSetBits(int L, int R)
    {
        int result = 0;
        for (int i = L; i <= R; i++)
        {
            if (isprime(__builtin_popcount(i)))
            {
                result++;
            }
        }
        return result;
    }
    bool isprime(int num)
    {
        if (num <= 1)
            return false;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
