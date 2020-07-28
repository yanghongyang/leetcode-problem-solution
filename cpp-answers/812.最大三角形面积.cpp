/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:01:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 23:09:40
 */
/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution
{
public:
    //海伦公式
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double maxArea = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size() - 1; j++)
            {
                for (int k = 0; k < points.size() - 2; k++)
                {
                    double a = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                    double b = sqrt(pow(points[i][0] - points[k][0], 2) + pow(points[i][1] - points[k][1], 2));
                    double c = sqrt(pow(points[j][0] - points[k][0], 2) + pow(points[j][1] - points[k][1], 2));
                    double halfP = (a + b + c) / 2;
                    double area = sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end
