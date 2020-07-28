/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 21:35:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 21:43:17
 */
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        if (!word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        board[i][j] = c;
        return ret;
    }
};
// @lc code=end
