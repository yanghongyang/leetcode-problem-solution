/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-16 07:41:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-16 08:13:02
 */
/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution
{
private:
    static constexpr int UNORDERED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    vector<int> color;
    bool valid;

public:
    void dfs(int node, int c, const vector<vector<int>> &graph)
    {
        color[node] = c;
        int cNei = (c == RED ? GREEN : RED);
        for (int neighbor : graph[node])
        {
            if (color[neighbor] == UNORDERED)
            {
                dfs(neighbor, cNei, graph);
                if (!valid)
                {
                    return;
                }
            }
            else
            {
                if (color[neighbor] != cNei)
                {
                    valid = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        valid = true;
        color.assign(n, UNORDERED);
        for (int i = 0; i < n && valid; i++)
        {
            if (color[i] == UNORDERED)
            {
                dfs(i, RED, graph);
            }
        }
        return valid;
    }
};
// @lc code=end
