/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-03 16:23:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-03 16:28:15
 */
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size(), n = matrix[0].size();

        int start = 0, end = m * n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int e = matrix[mid / n][mid % n];
            if (e < target)
            {
                start = mid + 1;
            }
            else if (e > target)
            {
                end = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
