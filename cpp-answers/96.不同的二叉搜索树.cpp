/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-15 22:27:51
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-15 23:14:35
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
// @lc code=end
