/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 10:12:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 11:50:04
 */
/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> mp;
        int n = wall.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                sum += wall[i][j];
                mp[sum]++;
            }
        }
        int ans = 0;
        for (auto m : mp)
        {
            if (m.second > ans)
                ans = m.second;
        }
        return n - ans;
    }
};
// @lc code=end
