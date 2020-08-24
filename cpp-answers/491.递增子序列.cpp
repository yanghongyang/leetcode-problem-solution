/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 07:08:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 07:42:59
 */
/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution
{
public:
    //超级笨的dfs
    /*     void dfs(int i, vector<int> tmp, set<vector<int>> &res, vector<int> &nums, int n, int prenumber)
    {
        if (i == n)
        {
            return;
        }
        if (tmp.size() >= 2)
        {
            res.insert(tmp);
        }
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] >= prenumber)
            {
                tmp.push_back(nums[j]);
                dfs(j, tmp, res, nums, n, nums[j]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> st;
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            tmp.push_back(nums[i]);
            dfs(i, tmp, st, nums, n, nums[i]);
        }
        for (auto it : st)
        {
            res.push_back(it);
        }
        return res;
    } */
    void dfs(int id, int prenumber, vector<int> &tmp, vector<vector<int>> &res, vector<int> &nums)
    {
        if (id == nums.size())
        {
            if (tmp.size() >= 2)
                res.push_back(tmp);
            return;
        }
        if (nums[id] >= prenumber)
        {
            tmp.push_back(nums[id]);
            dfs(id + 1, nums[id], tmp, res, nums);
            tmp.pop_back();
        }
        if (nums[id] != prenumber)
        {
            dfs(id + 1, prenumber, tmp, res, nums);
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        dfs(0, INT_MIN, tmp, res, nums);
        return res;
    }
};
// @lc code=end
