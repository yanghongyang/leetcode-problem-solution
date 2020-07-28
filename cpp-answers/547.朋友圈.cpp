/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-05 16:10:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 16:16:09
 */
/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution
{
public:
    int find(int x, vector<int> &parents)
    {
        return parents[x] == x ? x : find(parents[x], parents);
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        if (M.size() == 0)
            return 0;
        int n = M.size();
        vector<int> groups(n, 0);
        int count = n;
        for (int i = 0; i < n; i++)
            groups[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (M[i][j])
                {
                    int group1 = find(i, groups);
                    int group2 = find(j, groups);
                    if (group1 != group2)
                    {
                        groups[group1] = group2;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end
