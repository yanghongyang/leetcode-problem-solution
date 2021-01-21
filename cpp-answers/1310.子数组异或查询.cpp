/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        int qn = queries.size();
        vector<int> xorv(n, 0);
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp ^= arr[i];
            xorv[i] = (tmp);
        }
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            if (l == 0)
            {
                ans[i] = (xorv[r]);
                continue;
            }
            int t = xorv[r] ^ xorv[l - 1];
            ans[i] = (t);
        }
        return ans;
    }
};
// @lc code=end
