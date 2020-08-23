/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 15:43:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 15:50:06
 */
/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution
{
public:
    int numberOfSteps(int num)
    {
        if (num == 0)
            return num;
        int cnt = 0;
        while (num)
        {
            if (num % 2 == 1)
            {
                num -= 1;
                cnt++;
            }
            else
            {
                num >>= 1;
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
