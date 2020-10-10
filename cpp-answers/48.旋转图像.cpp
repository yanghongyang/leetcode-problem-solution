/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-11 07:52:18
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-11 07:54:33
 */
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end
