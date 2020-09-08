/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-08 22:30:28
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-08 22:35:18
 */
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    void dfs(int start, int n, int k, vector<int> tmp, vector<vector<int>> &res)
    {
        if (k == 0)
        {
            res.push_back(tmp);
            return;
        }
        if (start <= n - k)
        {
            dfs(start + 1, n, k, tmp, res);
        }
        tmp.push_back(start);
        dfs(start + 1, n, k - 1, tmp, res);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(1, n, k, tmp, res);
        return res;
    }
};
// @lc code=end
