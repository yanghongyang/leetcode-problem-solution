/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-12 09:01:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-12 09:13:46
 */
/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution
{
public:
    int numPrimeArrangements(int n)
    {
        int count = 0;
        int flag = 1;
        if (n == 1 || n == 2)
            return 1;
        for (int j = 3; j <= n; j++)
        {
            flag = 1;
            for (int i = 2; i * i <= j; i++)
            {
                if (j % i == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                count++;
        }
        count++;
        int num = 0;
        num += (Factorial(count) * Factorial(n - count)) % (1000000000 + 7);
        return num;
    }

    long long Factorial(int n)
    {
        long long sum = 1;
        for (int i = 1; i <= n; i++)
        {
            sum *= i;
            sum = sum % (1000000000 + 7);
        }
        return sum;
    }
};
// @lc code=end
