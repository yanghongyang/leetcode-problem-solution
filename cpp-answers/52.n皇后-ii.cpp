/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-17 07:46:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-17 07:50:54
 */
/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, true);
        vector<bool> anti(2 * n - 1, true);
        vector<bool> main(2 * n - 1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, main, anti, count);
        return count;
    }

    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool> &main, vector<bool> &anti, int &count)
    {
        if (i == row.size())
        {
            count++;
            return;
        }
        for (int j = 0; j < col.size(); j++)
        {
            if (col[j] && main[i + j] && anti[i + col.size() - 1 - j])
            {
                row[i] = j;
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
                dfs(i + 1, row, col, main, anti, count);
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
            }
        }
    }
};
// @lc code=end
