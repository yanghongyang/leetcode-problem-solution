/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 14:43:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 14:44:28
 */
/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (auto &v : A)
        {
            reverse(v.begin(), v.end());
            for (auto &n : v)
            {
                n = !n;
            }
        }
        return A;
    }
};
// @lc code=end
