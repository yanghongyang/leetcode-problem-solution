/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:39:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 11:54:46
 */
/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        //暴力枚举
        if (num <= 0)
            return false;
        int sum = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i * i != num)
                {
                    sum += num / i;
                }
            }
        }
        return sum == 2 * num;
        //欧几里得-欧拉定理
    }
};
// @lc code=end
