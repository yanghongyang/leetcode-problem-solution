/*
 * @Author: your name
 * @Date: 2020-05-29 23:50:00
 * @LastEditTime: 2020-05-30 00:02:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\28.实现-str-str.cpp
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/* 暴力求解
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};*/
/*另一种解法
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        int p = 0;
        while (p + n - 1 < m)
        {
            if (haystack.substr(p, n) == needle)
            {
                return p;
            }
            while (p++ + n - 1 < m && haystack[p] != needle[0])
                ;
        }
        return -1;
    }
};*/
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (!n)
        {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == n)
            {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j])
            {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }

private:
    vector<int> kmpProcess(string needle)
    {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;)
        {
            if (needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }
            else if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};
// @lc code=end
