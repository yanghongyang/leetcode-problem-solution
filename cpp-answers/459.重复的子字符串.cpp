/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 07:40:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-24 11:56:30
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
    /*     bool repeatedSubstringPattern(string s)
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
    } */
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return true;
        if (s.size() == 1)
            return false;
        int n = s.size();
        for (int i = 1; i * 2 <= n; i++)
        {
            if (n % i == 0)
            {
                bool flag = true;
                for (int j = i; j < n; j++)
                {
                    if (s[j] != s[j - i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return true;
            }
        }
        return false;
        /*
        string str = s + s;
        str = str.substr(1, str.size() - 2);
        if (str.find(s) == -1)
            return false;
        return true;*/
    }
};
// @lc code=end
