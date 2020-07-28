/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:35:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:43:46
 */
/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        /*使用sqrt函数
        for (long a = 0; a <= sqrt(c); a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
        */
        //费马平方和定理：一个非负整数 能够表示为两个整数的平方和，当且仅当c 的所有形如 4k + 3 的质因子的幂次均为偶数。
        //先对c进行质因数分解，再判断形如4k+3的质因子的幂次是否均为偶数。
        for (int i = 2; i * i <= c; i++)
        {
            int count = 0;
            if (c % i == 0)
            {
                while (c % i == 0)
                {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};
// @lc code=end
