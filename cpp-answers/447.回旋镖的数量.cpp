/*
 * @Author: your name
 * @Date: 2020-06-09 09:16:14
 * @LastEditTime: 2020-06-09 11:01:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\447.回旋镖的数量.cpp
 */
/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int points_size = points.size();
        //first存距离的平方
        //second存距离出现的次数
        unordered_map<int, int> count;
        int ans = 0;
        for (int i = 0; i < points_size; i++)
        {
            count.clear();
            int x = points[i][0];
            int y = points[i][1];
            for (int j = 0; j < points_size; j++)
            {
                if (j == i)
                    continue;
                int xx = points[j][0];
                int yy = points[j][1];
                int distance = (xx - x) * (xx - x) + (yy - y) * (yy - y);
                ++count[distance];
            }
            for (auto &k : count)
            {
                if (k.second >= 2)
                    ans += k.second * (k.second - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
