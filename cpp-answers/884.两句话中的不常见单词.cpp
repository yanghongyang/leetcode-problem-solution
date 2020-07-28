/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-18 09:17:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-18 09:54:29
 */
/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        unordered_map<string, int> mp;
        vector<string> out;

        string word;
        istringstream ss(A + " " + B);

        while (ss >> word)
            mp[word]++;
        unordered_map<string, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second == 1)
                out.push_back(itr->first);
        }
        return out;
    }
};
// @lc code=end
