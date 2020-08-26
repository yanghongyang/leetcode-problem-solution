/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &res, vector<int> nums, int j)
    {
        if (i == j - 1)
        {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (i != k && nums[i] == nums[k])
                continue;
            swap(nums[i], nums[k]);
            dfs(i + 1, res, nums, j);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        dfs(0, res, nums, n);
        return res;
    }
};
// @lc code=end
