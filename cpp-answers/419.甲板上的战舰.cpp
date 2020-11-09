/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-09 11:31:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-09 11:41:28
 */
/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<vector<char>> &board, int i, int j) //检查当前位置是新的战舰还是之前已经统计过的战舰
    {
        bool top = false, left = false;
        int x = i - 1, y = j;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        {
            top = true;
        }
        else if (board[x][y] == '.')
        {
            top = true; //这说明战舰可能是横着的
        }
        x = i, y = j - 1;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
        {
            left = true;
        }
        else if (board[x][y] == '.')
        {
            left = true; //这说明战舰可能是竖着的
        }
        return left && top;
    }
    int countBattleships(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size(); //n行m列
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X')
                {
                    if (check(board, i, j))
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
