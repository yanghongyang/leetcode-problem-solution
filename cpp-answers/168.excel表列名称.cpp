/*
 * @Author: your name
 * @Date: 2020-06-05 21:49:23
 * @LastEditTime: 2020-06-05 21:51:54
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\168.excel表列名称.cpp
 */
/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        while (n > 0)
        {
            res = char('A' + (n - 1) % 26) + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};
// @lc code=end
