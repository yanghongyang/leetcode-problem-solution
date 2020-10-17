/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-17 07:58:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-17 08:03:32
 */
/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                //这个边界判断我打满分！
                for (int I = max(i - 1, 0); I < min(i + 2, m); I++)
                {
                    for (int J = max(j - 1, 0); J < min(j + 2, n); J++)
                    {
                        count += board[I][J] & 1;
                    }
                }
                if (count == 3 || count - board[i][j] == 3)
                {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
        }
    }
};
// @lc code=end
