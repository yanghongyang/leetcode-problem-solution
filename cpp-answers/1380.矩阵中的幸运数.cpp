/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 13:53:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 14:14:18
 */
/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution
{
public:
    /*     vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        unordered_map<int, int> rowmini;
        for (int i = 0; i < m; i++)
        {
            int tmp = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (tmp > matrix[i][j])
                {
                    tmp = matrix[i][j];
                    rowmini[i] = j;
                }
            }
        }
        for (auto rm : rowmini)
        {
            int col = rm.second;
            int tmp = matrix[rm.first][rm.second];
            bool flag = true;
            for (int i = 0; i < m; i++)
            {
                if (tmp < matrix[i][col])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(matrix[rm.first][rm.second]);
            }
        }
        return ans;
    } */
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rmin(m, INT_MAX);
        vector<int> cmax(n, INT_MIN);
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rmin[i] = min(rmin[i], matrix[i][j]);
                cmax[j] = max(cmax[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j])
                    ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end
