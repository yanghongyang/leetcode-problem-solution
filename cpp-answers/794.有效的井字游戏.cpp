/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-13 07:36:56
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-13 07:55:21
 */
/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution
{
public:
    bool checkRow(string s)
    {
        char check = s[0];
        for (char ch : s)
        {
            if (ch == ' ' || ch != check)
                return false;
        }
        return true;
    }
    bool checkCol(vector<string> &board, int i)
    {
        int r = board.size();
        char check = board[0][i];
        for (int j = 0; j < r; j++)
        {
            if (board[j][i] == ' ' || board[j][i] != check)
                return false;
        }
        return true;
    }
    bool checkDiag(vector<string> &board)
    {
        char check = board[0][0];
        int r = board.size();
        for (int i = 0; i < r; i++)
        {
            if (board[i][i] == ' ' || board[i][i] != check)
                return false;
        }
        return true;
    }
    bool checkDiagRev(vector<string> &board)
    {
        char check = board[0][2];
        int r = board.size();
        for (int i = 0; i < r; i++)
        {
            if (board[i][r - i - 1] == ' ' || board[i][r - i - 1] != check)
                return false;
        }
        return true;
    }
    bool validTicTacToe(vector<string> &board)
    {
        int noOs = 0;
        int noXs = 0;

        bool flagX = false;
        bool flagO = false;

        for (int i = 0; i < board.size(); i++)
        {
            if (checkRow(board[i]))
            {
                if (board[i][0] == 'X')
                {
                    if (flagO)
                        return false;
                    flagX = true;
                }
                if (board[i][0] == 'O')
                {
                    if (flagX)
                        return false;
                    flagO = true;
                }
            }
            if (checkCol(board, i))
            {
                if (board[0][i] == 'X')
                {
                    if (flagO)
                        return false;
                    flagX = true;
                }
                if (board[0][i] == 'O')
                {
                    if (flagX)
                        return false;
                    flagO = true;
                }
            }

            for (char ch : board[i])
            {
                if (ch == 'O')
                    noOs++;
                else if (ch == 'X')
                    noXs++;
            }
        }
        if (checkDiag(board))
        {
            if (board[0][0] == 'X')
            {
                if (flagO)
                    return false;
                flagX = true;
            }
            if (board[0][0] == 'O')
            {
                if (flagX)
                    return false;
                flagO = true;
            }
        }
        if (checkDiagRev(board))
        {
            if (board[0][2] == 'X')
            {
                if (flagO)
                    return false;
                flagX = true;
            }
            if (board[0][2] == 'O')
            {
                if (flagX)
                    return false;
                flagO = true;
            }
        }
        if (noOs > noXs || ((noXs - noOs) > 1))
            return false;
        if (flagX && (noXs <= noOs))
            return false;
        if (flagO && (noXs != noOs))
            return false;

        if (flagX && flagO)
            return false;
        return true;
    }
};
// @lc code=end
