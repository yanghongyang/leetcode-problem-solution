<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 21:18:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 21:31:07
-->
#### 前言
虽然不太能理解为啥在 `vscode` 插件上，这题的 `tag` 是动态规划和滑动窗口......但使用 `DFS` 是可以做的。

#### 考点
- 深度优先搜索

#### 题目分析
这道题很明显，是一道地图题。可以将 **网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量** 理解为 **矩阵中不能够通过某条路径到达边界的点的数量** 。那么可以从外向内，对矩阵的边界上值为 `1` 的点进行 `DFS` ，并将可以到达的点置为 `0` ，之后再次遍历矩阵，只要矩阵中的元素值为 `1` ，则意味着它不能够通过某条路径到达边界。

**代码**
```cpp []
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
```