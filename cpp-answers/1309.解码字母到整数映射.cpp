/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-16 06:56:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-16 06:58:05
 */
/*
 * @lc app=leetcode.cn id=1309 lang=cpp
 *
 * [1309] 解码字母到整数映射
 */

// @lc code=start
class Solution
{
public:
    string freqAlphabets(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size();)
        {
            if (i + 2 < s.size() && s[i + 2] == '#')
            {
                int ss = (s[i] - '0') * 10 + (s[i + 1] - '0');
                ans += char(ss + 'a' - 1);
                i += 3;
            }
            else
            {
                ans += char(s[i] - '0' - 1 + 'a');
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end
