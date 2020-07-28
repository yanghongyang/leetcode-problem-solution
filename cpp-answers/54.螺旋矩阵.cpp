/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 21:12:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 21:34:36
 */
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    /*按层遍历
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1;
        int top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom)
        {
            for (int column = left; column <= right; column++)
            {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++)
            {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom)
            {
                for (int column = right - 1; column > left; column--)
                {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--)
                {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }*/
    //模拟
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++)
        {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
            {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};
// @lc code=end
