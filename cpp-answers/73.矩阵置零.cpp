/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-26 08:20:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-24 09:29:21
 */
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution
{
public:
    /*     void setZeroes(vector<vector<int>> &matrix)
    {
        int rowsize = matrix.size();
        int columnsize = matrix[0].size();
        vector<int> rowmarker(rowsize, 1);
        vector<int> columnmarker(columnsize, 1);
        //先用两个vector分别记录出现0的时候的行号和列号
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < columnsize; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowmarker[i] = 0;
                    columnmarker[j] = 0;
                }
            }
        }
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < columnsize; j++)
            {
                if (rowmarker[i] == 0 || columnmarker[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    } */
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool flag = false; //用作第一列的标识位
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) //设置标识位
        {
            if (matrix[i][0] == 0)
                flag = true; //单独判断第一列的情况
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (flag)
                matrix[i][0] = 0; //第一列元素单独判断
        }
    }
};
// @lc code=end
