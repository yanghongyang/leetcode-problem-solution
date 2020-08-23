/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 12:01:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 12:14:08
 */
/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution
{
public:
    //寻找公共前缀
    /* int rangeBitwiseAnd(int m, int n)
    {
        int shift = 0;
        while (m < n)
        {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    } */
    // Brian Kernighan 算法
    int rangeBitwiseAnd(int m, int n)
    {
        while (m < n)
        {
            //抹掉n最右边的1
            n = n & (n - 1);
        }
        return n;
    }
};
// @lc code=end
