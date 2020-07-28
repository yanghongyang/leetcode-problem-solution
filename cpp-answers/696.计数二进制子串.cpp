/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-28 22:52:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 22:55:04
 */
/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int ones = 0;
        int zeros = 0;
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            ones = 0;
            while (i < s.size() && s[i] == '1')
            {
                ones++;
                i++;
            }
            res += min(ones, zeros);
            zeros = 0;
            while (i < s.size() && s[i] == '0')
            {
                zeros++;
                i++;
            }
            res += min(ones, zeros);
        }
        return res;
    }
};
// @lc code=end
