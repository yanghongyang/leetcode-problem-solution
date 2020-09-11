/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-11 10:26:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-11 10:33:06
 */
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    void dfs(int sum, int id, int k, vector<int> &candidates, vector<int> &tmp, vector<vector<int>> &res)
    {
        if (sum == 0 && tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        for (int j = id; j < candidates.size(); j++)
        {
            if (sum - candidates[j] >= 0)
            {
                tmp.push_back(candidates[j]);
                dfs(sum - candidates[j], j + 1, k, candidates, tmp, res);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> candidates;
        for (int i = 1; i <= 9; i++)
        {
            candidates.push_back(i);
        }
        dfs(n, 0, k, candidates, tmp, res);
        return res;
    }
};
// @lc code=end
