/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> cnt;
        priority_queue<pair<int, char>> mh; //用大根堆对hashmap进行处理
        for (auto &c : s)
        {
            cnt[c]++;
        }
        for (auto it : cnt)
        {
            mh.push({it.second, it.first});
        }
        string ans = "";
        while (!mh.empty())
        {
            for (int i = 0; i < mh.top().first; i++)
            {
                ans += mh.top().second;
            }
            mh.pop();
        }
        return ans;
    }
};
// @lc code=end
