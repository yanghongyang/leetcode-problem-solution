/*
 * @Author: your name
 * @Date: 2020-06-06 22:42:23
 * @LastEditTime: 2020-06-06 22:48:51
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\191.位-1-的个数.cpp
 */
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};
// @lc code=end
