/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-01 20:34:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-01 20:36:27
 */
/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            auto &group = groups[groupSizes[i]];
            group.push_back(i);
            if (group.size() == groupSizes[i])
            {
                res.push_back(group);
                group.clear();
            }
        }
        return res;
    }
};
// @lc code=end
