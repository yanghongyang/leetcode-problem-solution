/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-09 11:44:36
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-09 11:51:25
 */
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    bool check(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void partition(string &s, int start, vector<string> &group, vector<vector<string>> &res)
    {
        int n = s.size();
        if (start == n)
        {
            res.push_back(group);
        }
        else
        {
            for (int i = start; i < n; i++)
            {
                if (check(s, start, i))
                {
                    group.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, group, res);
                    group.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> group;
        partition(s, 0, group, res);
        return res;
    }
};
// @lc code=end
