/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-05 07:11:36
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 07:51:48
 */
/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution
{
public:
    //动态规划方法，如果没有n>30000剪枝的话会超时
    /*
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        if (n > 30000)
            return false;
        vector<bool> cur(m + 1, false);
        cur[0] = true;
        for (int j = 1; j <= n; j++)
        {
            bool pre = cur[0]; //在更新前使用值，pre意为p[i - 1][j - 1]的压缩空间优化
            cur[0] = cur[0] && p[j - 1] == '*';
            for (int i = 1; i <= m; i++)
            {
                bool temp = cur[i]; //在更新前记录数值
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else
                    cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m];
    }*/
    //另一种动态规划
    /*bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')
            {
                dp[0][i] = true;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }*/
    bool isMatch(string s, string p)
    {
        auto allStars = [](const string &str, int left, int right) {
            for (int i = left; i < right; i++)
            {
                if (str[i] != '*')
                    return false;
            }
            return true;
        };
        auto charMatch = [](char u, char v) {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*')
        {
            if (charMatch(s.back(), p.back()))
            {
                s.pop_back();
                p.pop_back();
            }
            else
                return false;
        }
        if (p.empty())
            return s.empty();
        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size())
        {
            if (p[pIndex] == '*')
            {
                pIndex++;
                sRecord = sIndex;
                pRecord = pIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex]))
            {
                ++sIndex;
                ++pIndex;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size())
            {
                sRecord++;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else
                return false;
        }
        return allStars(p, pIndex, p.size());
    }
};
// @lc code=end
