/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-01 19:14:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-01 19:18:13
 */
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    //利用栈的思想，如果遇到相同的字母就弹出，否则就压入
    string removeDuplicates(string S)
    {
        string s2;
        for (char &c : S)
        {
            if (s2.empty())
            {
                s2.push_back(c);
            }
            else if (c == s2.back())
            {
                s2.pop_back();
            }
            else
                s2.push_back(c);
        }
        return s2;
    }
};
// @lc code=end
