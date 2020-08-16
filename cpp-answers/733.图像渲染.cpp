/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 11:48:59
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-16 09:24:16
 */
/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int r, int c, int m, int n, int target, int newColor)
    {
        if (r < 0 || c < 0 || r == m || c == n || image[r][c] == newColor || image[r][c] != target)
            return;
        image[r][c] = newColor;
        dfs(image, r + 1, c, m, n, target, newColor);
        dfs(image, r - 1, c, m, n, target, newColor);
        dfs(image, r, c + 1, m, n, target, newColor);
        dfs(image, r, c - 1, m, n, target, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        dfs(image, sr, sc, m, n, image[sr][sc], newColor);
        return image;
    }
};
// @lc code=end
