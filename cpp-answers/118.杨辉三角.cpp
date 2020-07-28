/*
 * @Author: your name
 * @Date: 2020-06-03 13:45:23
 * @LastEditTime: 2020-06-05 20:33:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \postwoman-mastere:\leetcode刷题\118.杨辉三角.cpp
 */
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> row;
        for (int i = 0; i < numRows; i++)
        {
            row.push_back(1);
            for (int j = i - 1; j > 0; j--)
            {
                row[j] = row[j - 1] + row[j];
            }
            result.push_back(row);
        }
        return result;
    }
};
// @lc code=end
