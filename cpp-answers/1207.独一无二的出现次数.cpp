/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 17:09:30
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 17:10:50
 */
/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (auto i : arr)
            m[i]++;
        for (auto i : m)
            s.insert(i.second);
        return m.size() == s.size();
    }
};
// @lc code=end
