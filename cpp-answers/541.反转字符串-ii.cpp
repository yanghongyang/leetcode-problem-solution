/*
 * @Author: your name
 * @Date: 2020-06-11 07:22:22
 * @LastEditTime: 2020-06-11 07:25:02
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\541.反转字符串-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        //如果k>s的长度，那么返回反转后的s
        if (k >= s.size())
        {
            reverse(s.begin(), s.end());
            return s;
        }
        int j = 0;
        while (j < s.size())
        {
            if (j + k < s.size())
                reverse(s.begin() + j, s.begin() + j + k);
            else
                reverse(s.begin() + j, s.end());

            j += 2 * k;
        }
        return s;
    }
};
// @lc code=end
