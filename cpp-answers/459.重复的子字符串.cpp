/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 07:40:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 08:06:45
 */
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return true;
        if (s.size() == 1)
            return false;
        const int nMiddleIndex = s.size() / 2 - 1;
        for (int i = 0; i <= nMiddleIndex; i++)
        {
            int nLength = i + 1;
            if (s.size() % nLength != 0)
                continue;
            int j = 0;
            for (; j < s.size() - nLength; j++)
            {
                if (s[j] != s[j + nLength])
                    break;
            }
            if (j == s.size() - nLength)
                return true;
        }
        return false;
    }
};
// @lc code=end
