/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-22 12:02:45
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-22 12:16:33
 */
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    //迭代法
    /*     vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res = {{}};
        for (int num : nums)
        {
            int n = res.size();
            for (int i = 0; i < n; i++)
            {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    } */
    //递归法
    /*     void dfs(vector<vector<int>> &res, int i, vector<int> &tmp, vector<int> &nums, int n)
    {
        if (i > n)
            return;
        res.push_back(tmp);
        for (int j = i; j < n; j++)
        {
            tmp.push_back(nums[j]);
            dfs(res, j + 1, tmp, nums, n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, 0, tmp, nums, nums.size());
        return res;
    } */
    //位运算
    //考察数学基础知识，含有N个不重复元素的集合的子集为2^n个
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>> res(p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
