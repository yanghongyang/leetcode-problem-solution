/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:26:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-24 06:49:43
 */
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution
{
public:
    bool process(const string &s, const string &t, int i, int j)
    {
        if (i == s.size())
            return true;
        if (j == t.size())
            return false;
        if (s.at(i) == t.at(j))
            return process(s, t, i + 1, j + 1);
        return process(s, t, i, j + 1);
    }
    bool isSubsequence(string s, string t)
    {
        /*非递归解法
        unordered_map<char, vector<int>> hg;
        for (int i = 0; i < t.length(); i++)
        {
            hg[t[i]].push_back(i);
        }
        int prev = -1;
        for (auto c : s)
        {
            auto it = hg.find(c);
            if (it == hg.end())
                return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin();
            if (pos == vec.size())
                return false;
            prev = vec[pos];
        }
        return true;
        */
        return process(s, t, 0, 0);
    }
};
// @lc code=end
