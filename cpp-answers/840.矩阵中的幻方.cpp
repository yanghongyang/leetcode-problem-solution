/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 15:11:05
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 15:37:03
 */
/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 */

// @lc code=start
class Solution
{
public:
    //3阶幻方总共h只有固定的8种。
    //中心是5，然后对应的行和列呈旋转镜像分布
    vector<int> m = {8, 1, 6, 7, 2, 9, 4, 3, 8, 1, 6, 7, 2, 9, 4, 3};
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int count = 0;
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (grid[i][j] == 5)
                {
                    vector<int> around;
                    for (int k = 0; k < 8; k++)
                    {
                        around.push_back(grid[i + di[k]][j + dj[k]]);
                    }
                    count += IsMagic(around);
                }
            }
        }
        return count;
    }
    bool IsMagic(vector<int> &v)
    {
        for (int i = 0; i < 8; i += 2)
        {
            if (m[i] == v[0])
                return v == vector<int>(m.begin() + i, m.begin() + i + 8) || v == vector<int>(m.rbegin() + 7 - i, m.rbegin() + 15 - i);
        }
        return false; //奇数元素
    }
};
// @lc code=end
