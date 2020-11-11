/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-11 17:16:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-11 17:21:24
 */
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.size() <= 0)
            return false;
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string tmp = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()] == true;
    }
};
// @lc code=end
