/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-16 10:56:29
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-16 11:11:40
 */
/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] > '0')
                dp[i + 1] = dp[i];
            int j = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (j > 9 && j <= 26)
                dp[i + 1] += dp[i - 1];
            if (dp[i + 1] == 0)
                return 0;
        }
        return dp[s.size()];
    }
};
// @lc code=end
