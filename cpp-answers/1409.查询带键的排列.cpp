/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-03 11:11:40
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-03 11:16:21
 */
/*
 * @lc app=leetcode.cn id=1409 lang=cpp
 *
 * [1409] 查询带键的排列
 */

// @lc code=start
class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> p(m);
        iota(p.begin(), p.end(), 1);
        vector<int> ans;
        for (int query : queries)
        {
            int pos = -1;
            for (int i = 0; i < m; i++)
            {
                if (p[i] == query)
                {
                    pos = i;
                    break;
                }
            }
            ans.push_back(pos);
            p.erase(p.begin() + pos);
            p.insert(p.begin(), query);
        }
        return ans;
    }
};
// @lc code=end
