/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-11 17:43:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-11 17:54:56
 */
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (idx != 0)
                    s[idx++] = ' ';
                int end = i;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                //反转整个单词
                reverse(s.begin() + idx - (end - i), s.begin() + idx);

                i = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
// @lc code=end
