/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 19:37:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 19:51:29
 */
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() <= 0)
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = m - 1;
        while (r < n && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
            {
                r++;
            }
            else
            {
                c--;
            }
        }
        return false;
    }
};
// @lc code=end
