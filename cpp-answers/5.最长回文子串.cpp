/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-02 20:20:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-02 22:18:26
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
/*
class Solution
{
public:

    string longestPalindrome(string s)
    {
        //动态规划
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i + l < n; i++)
            {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = 1;
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && l + 1 > ans.size())
                    ans = s.substr(i, l + 1);
            }
        }
        return ans;
    }
};*/
class Solution
{
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s)
    {
        //中心扩展算法
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
//曼彻斯特算法
// @lc code=end
