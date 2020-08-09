/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void dfs(int start, vector<int>& tmp, vector<vector<int>>& res, vector<int>& nums, int n)
    {
        if(start == n)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = 0; i <= tmp.size(); i++)
        {
            tmp.insert(tmp.begin() + i, nums[start]);
            dfs(start + 1, tmp, res, nums, n);
            tmp.erase(tmp.begin() + i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(0, tmp, res, nums, nums.size());
        return res;
    }
};
// @lc code=end

