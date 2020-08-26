/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool rowcheck(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++)
            {
                mp[board[i][j]]++;
                if (mp[board[i][j]] != 1 && board[i][j] != '.')
                    return false;
            }
        }
        return true;
    }
    bool colcheck(vector<vector<char>> &board)
    {
        for (int j = 0; j < 9; j++)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < 9; i++)
            {
                mp[board[i][j]]++;
                if (mp[board[i][j]] != 1 && board[i][j] != '.')
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool gridcheck(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board[0].size(); j += 3)
            {
                unordered_map<char, int> mp;
                for (int k1 = 0; k1 < 3; k1++)
                {
                    for (int k2 = 0; k2 < 3; k2++)
                    {
                        mp[board[i + k1][j + k2]]++;
                        if (mp[board[i + k1][j + k2]] != 1 && board[i + k1][j + k2] != '.')
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return rowcheck(board) && colcheck(board) && gridcheck(board);
    }
};
// @lc code=end
