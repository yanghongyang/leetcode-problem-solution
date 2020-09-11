/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-11 10:55:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-11 11:12:14
 */
/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution
{
public:
    int integerReplacement(int n)
    {
        //要处理溢出的情况，但是C++的这种写法会TLE所以先判断一下
        if (n == INT_MAX)
            return 32;
        int cnt = 0;
        while (n != 1)
        {
            if ((n & 1) == 0)
                n >>= 1; //如果是偶数的话直接除以2就行啦
            else
            {
                if (((n & 2) == 0) || n == 3)
                    n--;
                else
                    n++;
            }
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end
