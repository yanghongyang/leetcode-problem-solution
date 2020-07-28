/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 17:59:15
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 18:01:36
 */
/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        set<int> s;
        vector<int> ans{};
        int mini = INT_MAX;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
                s.insert(i);
        }
        for (int i = 0; i < S.size(); i++)
        {
            for (auto x : s)
            {
                if (abs(i - x) < mini)
                {
                    mini = abs(i - x);
                }
            }
            ans.push_back(mini);
            mini = INT_MAX;
        }
        return ans;
    }
};
// @lc code=end
