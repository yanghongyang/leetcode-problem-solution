/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-29 17:04:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-29 22:58:28
 */
/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        if (s.size() <= 0 || words.size() < 0 || words[0].size() < 0)
            return ans;
        unordered_map<string, int> cnt;
        for (auto word : words)
        {
            cnt[word]++;
        }
        int n = s.size();
        int wl = words[0].size();
        int len = wl * words.size();
        for (int i = 0; i < n - len + 1; i++)
        {
            unordered_map<string, int> curcnt;
            int j = 0;
            for (; j < words.size(); j++)
            {
                string word = s.substr(i + j * wl, wl); //在s的i+j*wl处取长度为wl的子串
                if (cnt.find(word) != cnt.end())        //如果在cnt中可以找到
                {
                    curcnt[word]++;               //在curcnt数组中该word数++
                    if (curcnt[word] > cnt[word]) //如果当前curcnt[word]个数超过了cnt[word]，也就是超过了words中该word出现的次数，则失败
                        break;
                }
                else //找不到的话就肯定是失败，跳出循环
                    break;
            }
            if (j == words.size())
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
