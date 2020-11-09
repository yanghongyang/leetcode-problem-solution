/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-09 11:17:02
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-09 11:29:00
 */
/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution
{
public:
    /*     vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v) {
            return u[0] * u[0] + u[1] * u[1] < v[0] * v[0] + v[1] * v[1];
        });
        return {points.begin(), points.begin() + K};
    } */
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; i++)
        {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int n = points.size();
        for (int i = K; i < n; i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first)
            {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty())
        {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
