/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-01 08:25:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-01 08:59:21
 */
/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    //暴力法：矩阵面积=宽*高
    //对每一行每一列进行遍历，找到以一行中对应的列为起点向上能达到的最小宽度，再乘以高，即为以matrix[i][j]为起点能达到的最大面积
    //每一行这样统计，求最大值即可。
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() <= 0)
            return 0;
        vector<vector<int>> width(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                //更新width
                if (matrix[i][j] == '1')
                {
                    if (j == 0)
                        width[i][j] = 1;
                    else
                        width[i][j] = width[i][j - 1] + 1;
                }
                else
                {
                    width[i][j] = 0;
                }
                //记录所有行中的最小数
                int minwidth = width[i][j];
                //向上扩展行
                for (int up = i; up >= 0; up--)
                {
                    int height = i - up + 1;
                    minwidth = min(minwidth, width[up][j]);
                    maxArea = max(maxArea, minwidth * height);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end
