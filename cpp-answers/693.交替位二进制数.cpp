/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-19 08:39:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 09:04:24
 */
/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool bPrev = n & 1;
        n >>= 1;
        while (n)
        {
            bool bCur = n & 1;
            if (bCur == bPrev)
                return false;
            bPrev = bCur;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end
