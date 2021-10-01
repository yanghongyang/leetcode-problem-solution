/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 15:04:27
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 15:08:34
 */
/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> place;
        for (int i = 0; i < paths.size(); i++)
        {
            place.insert(paths[i][0]);
        }
        for (int i = 0; i < paths.size(); i++)
        {
            if (place.find(paths[i][1]) == place.end())
                return paths[i][1];
        }
        return "";
    }
};

// 另一种通过方式（同一种方法，用的 unordered_map）
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> cnt;
        for (auto p : paths)
        {
            cnt[p[0]] = 1;
        }
        for (auto p : paths)
        {
            if (cnt.count(p[1]) == 0)
            {
                return p[1];
            }
        }
        return "";
    }
};
// @lc code=end
