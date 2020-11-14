/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 08:55:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 09:07:31
 */
/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution
{
public:
    const int base = 1337;
    //ab % k = (a % k) * (b % k) % k
    //同样也可以把k进行分割和相加
    //f(a,1234567) = f(a,1234560) * f(a, 7) % k = f(f(a, 123456), 10) * f(a, 7) % k
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }

    int powmod(int a, int cnt)
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < cnt; i++)
        {
            result = (result * a) % base;
        }
        return result;
    }
};
// @lc code=end
