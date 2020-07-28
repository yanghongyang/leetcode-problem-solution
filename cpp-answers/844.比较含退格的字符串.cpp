/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:10:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 23:25:45
 */
/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> a;
        stack<char> b;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '#')
            {
                if (!a.empty())
                    a.pop();
            }
            else
                a.push(S[i]);
        }
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] == '#')
            {
                if (!b.empty())
                    b.pop();
            }
            else
                b.push(T[i]);
        }
        if (a.size() != b.size())
            return false;
        else if (a.size() == 0 && b.size() == 0)
            return true;
        else
        {
            while (!a.empty() && !b.empty())
            {
                if (a.top() == b.top())
                {
                    a.pop();
                    b.pop();
                }
                else
                    return false;
            }
            if (a.empty() && b.empty())
                return true;
        }
        return false;
    }
};
// @lc code=end
