/*
 * @Author: your name
 * @Date: 2020-05-28 21:19:13
 * @LastEditTime: 2020-05-28 21:25:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\7.整数反转.cpp
 */
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.21%)
 * Likes:    1908
 * Dislikes: 0
 * Total Accepted:    361.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long res = 0;
        while (x != 0)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (INT_MAX < res || INT_MIN > res) ? 0 : res;
    }
};
// @lc code=end
