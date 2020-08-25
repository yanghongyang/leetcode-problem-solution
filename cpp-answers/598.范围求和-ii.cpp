/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        for (auto e : ops)
        {
            m = min(m, e[0]);
            n = min(n, e[1]);
        }
        return m * n;
    }
};
// @lc code=end
