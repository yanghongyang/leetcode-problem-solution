/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-05 15:29:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 16:49:40
 */
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
/*dfs
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; j++)
        {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O')
        {
            board[i][j] = '1';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
};*/
class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int n = 0)
    {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unions(int x, int y)
    {
        //先查找x y所在集合的代表元素
        int px = find(x), py = find(y);
        if (px != py)
        {
            parent[px] = py;
        }
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    vector<pair<int, int>> neighbor = vector<pair<int, int>>{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isBorder(int i, int j, int m, int n)
    {
        return i == 0 || i == m - 1 || j == 0 || j == n - 1;
    }

    bool isValid(int row, int col, int m, int n)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size();
        int n = board[0].size();
        UnionFind uf(m * n + 1);
        int dummy = m * n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    int p = i * n + j;
                    if (!isBorder(i, j, m, n))
                    {
                        for (auto &nb : neighbor)
                        {
                            int row = i + nb.first, col = j + nb.second;
                            if (isValid(row, col, m, n) && board[row][col] == 'O')
                                uf.unions(p, p + nb.first * n + nb.second);
                        }
                    }
                    else
                    {
                        uf.unions(p, dummy);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (uf.find(i * n + j) != uf.find(dummy))
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end
