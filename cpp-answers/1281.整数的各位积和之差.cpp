/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-31 22:15:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-31 22:18:08
 */
/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        long long mulans = 1;
        long long addans = 0;
        while (n > 0)
        {
            int tmp = n % 10;
            mulans *= tmp;
            addans += tmp;
            n /= 10;
        }
        return mulans - addans;
    }
};
// @lc code=end
