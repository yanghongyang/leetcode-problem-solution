/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &matrix, bool &reachP, bool &reachA)
    {
        if (matrix[i][j] == -1 || (reachP && reachA))
            return; //如果已经遍历过了，或者已经满足条件了，就直接返回
        int tmp = matrix[i][j];
        matrix[i][j] = -1; //标记已经访问过了
        for (int k = 0; k < 4; k++)
        {
            int tx = i + direction[k][0], ty = j + direction[k][1]; //四个方向遍历
            if (tx < 0 || ty < 0)                                   //如果到达右上角
            {
                reachP = true;
            }
            else if (tx == matrix.size() || ty == matrix[0].size())
            {
                reachA = true;
            }
            else if (matrix[tx][ty] <= tmp)
            {
                dfs(tx, ty, matrix, reachP, reachA);
            }
        }
        matrix[i][j] = tmp; //恢复状态
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> res;
        if (matrix.size() <= 0)
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                bool reachP = false; //能否到达太平洋，默认为false
                bool reachA = false; //能否到达大西洋，默认为false
                dfs(i, j, matrix, reachP, reachA);
                if (reachP && reachA)
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
// @lc code=end