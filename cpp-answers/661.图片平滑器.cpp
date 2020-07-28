/*
 * @Author: your name
 * @Date: 2020-06-13 19:53:12
 * @LastEditTime: 2020-06-13 19:59:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\661.图片平滑器.cpp
 */
/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        vector<vector<int>> R(M.size(), vector<int>(M[0].size(), 0));
        int count;
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                count = 0;
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (k < 0 || l < 0)
                            continue;
                        if (k >= M.size() || l >= M[0].size())
                            continue;
                        count++;
                        R[i][j] += M[k][l];
                    }
                }
                R[i][j] /= count;
            }
        }
        return R;
    }
};
// @lc code=end
