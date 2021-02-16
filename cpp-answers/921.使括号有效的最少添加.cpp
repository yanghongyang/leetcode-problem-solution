/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        stack<char> s;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                s.push(S[i]);
            }
            else // if S[i] == ')'
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(S[i]);
                }
            }
        }
        return s.size();
    }
};
// @lc code=end
