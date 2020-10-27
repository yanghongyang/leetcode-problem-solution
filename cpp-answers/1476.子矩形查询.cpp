/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-28 00:30:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-28 00:33:53
 */
/*
 * @lc app=leetcode.cn id=1476 lang=cpp
 *
 * [1476] 子矩形查询
 */

// @lc code=start
class SubrectangleQueries
{
private:
    vector<vector<int>> rectangle;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        this->rectangle = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                rectangle[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return rectangle[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end
