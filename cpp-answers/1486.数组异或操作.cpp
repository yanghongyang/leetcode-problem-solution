/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-27 17:10:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-27 17:11:23
 */
/*
 * @lc app=leetcode.cn id=1486 lang=cpp
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        if (n > 1)
            return start ^ xorOperation(n - 1, start + 2);
        else
            return start;
    }
};
// @lc code=end
