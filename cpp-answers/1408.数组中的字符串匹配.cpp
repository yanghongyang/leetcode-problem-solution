/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:08:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:15:52
 */
/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    vector<string> stringMatching(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        vector<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[j].find(words[i]) != -1)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
