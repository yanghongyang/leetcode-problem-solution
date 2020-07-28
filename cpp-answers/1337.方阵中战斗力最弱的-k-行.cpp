/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 16:13:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 16:18:29
 */
/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 方阵中战斗力最弱的 K 行
 */

// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        vector<pair<int, int>> power;
        for (int i = 0; i < n; i++)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            power.emplace_back(sum, i);
        }
        sort(power.begin(), power.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(power[i].second);
        }
        return ans;
    }
};
// @lc code=end
