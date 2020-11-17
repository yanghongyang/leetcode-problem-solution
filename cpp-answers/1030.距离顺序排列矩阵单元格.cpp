/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-17 08:12:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-17 08:13:42
 */
/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<int>> res;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                res.push_back({i, j});
            }
        }
        sort(
            res.begin(), res.end(), [&](vector<int> a, vector<int> b) {
                int la = abs(a[0] - r0) + abs(a[1] - c0);
                int lb = abs(b[0] - r0) + abs(b[1] - c0);
                return la < lb;
            });
        return res;
    }
};
// @lc code=end
