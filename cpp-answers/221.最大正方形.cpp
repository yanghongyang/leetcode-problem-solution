/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-11 18:13:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-11 18:20:15
 */
/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int edge = 0;                                 //边长
        vector<vector<int>> dp(n, vector<int>(m, 0)); //n行m列矩阵
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || matrix[i][j] == '0') //边界和内部格子为0的情况，取决于当前格子的值
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; //边长取决于当前格子上方、左边、左斜上方的边长的最小值
                }
                edge = max(edge, dp[i][j]);
            }
        }
        return edge * edge;
    }
};
// @lc code=end
