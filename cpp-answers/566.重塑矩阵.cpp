/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:36:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 23:41:54
 */
/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int size = nums.size() * nums[0].size();
        int size2 = r * c;
        if (size != size2)
            return nums;
        int row = nums.size();
        int col = nums[0].size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        int l = 0;
        for (int i = 0, k = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++, l++)
            {
                if (l == c)
                {
                    k++;
                    l = 0;
                }
                res[k][l] = nums[i][j];
            }
            if (k == r)
                break;
        }
        return res;
    }
};
// @lc code=end
