/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 14:55:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 21:18:02
 */
/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, int row, int col, vector<vector<int>> &A)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || A[i][j] != 1)
            return;
        if (A[i][j] == 1)
        {
            A[i][j] = 0;
            dfs(i + 1, j, row, col, A);
            dfs(i - 1, j, row, col, A);
            dfs(i, j + 1, row, col, A);
            dfs(i, j - 1, row, col, A);
        }
    }
    int numEnclaves(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();
        if (m == 0)
            return 0;
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, m, n, A);
            dfs(i, n - 1, m, n, A);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, m, n, A);
            dfs(m - 1, i, m, n, A);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
