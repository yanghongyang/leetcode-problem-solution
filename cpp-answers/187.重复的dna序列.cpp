/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> MP;
        vector<string> res;

        for (int i = 0; i + 10 <= (int)(s.size()); i++)
        {
            string t = s.substr(i, 10);
            if (MP[t] == 1)
            {
                res.push_back(s.substr(i, 10));
            }
            MP[t]++;
        }

        return res;
    }
};
// @lc code=end
