/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    void dfs(int id, vector<int> &tmp, vector<vector<int>> &res, vector<int> &nums)
    {
        res.push_back(tmp);
        for (int i = id; i < nums.size(); i++)
        {
            if (i == id || nums[i] != nums[i - 1])
            {
                tmp.push_back(nums[i]);
                dfs(i + 1, tmp, res, nums);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(0, tmp, res, nums);
        return res;
    }
};
// @lc code=end
