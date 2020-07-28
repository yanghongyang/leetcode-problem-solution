/*
 * @Author: your name
 * @Date: 2020-05-28 22:13:21
 * @LastEditTime: 2020-05-28 22:30:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\20.有效的括号.cpp
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sta;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                sta.push(s[i]);
            else if (s[i] == ')')
            {
                if (sta.empty() || sta.top() != '(')
                    return false;
                else
                    sta.pop();
            }
            else if (s[i] == ']')
            {
                if (sta.empty() || sta.top() != '[')
                    return false;
                else
                    sta.pop();
            }
            else if (s[i] == '}')
            {
                if (sta.empty() || sta.top() != '{')
                    return false;
                else
                    sta.pop();
            }
        }
        return sta.empty();
    }
};
// @lc code=end
