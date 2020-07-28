/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 12:19:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 12:21:32
 */
/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
