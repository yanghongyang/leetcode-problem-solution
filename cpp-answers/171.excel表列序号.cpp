/*
 * @Author: your name
 * @Date: 2020-06-05 22:23:18
 * @LastEditTime: 2020-06-05 22:24:19
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\171.excel表列序号.cpp
 */
/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0;
        for (int i = s.size(); i > 0; i--)
        {
            res += (s[i - 1] - 'A' + 1) * pow(26, s.size() - i);
        }
        return res;
    }
};
// @lc code=end
