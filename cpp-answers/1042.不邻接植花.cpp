/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 12:11:31
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 12:20:21
 */
/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution
{
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>> &path)
    {
        vector<int> g[N];
        for (int i = 0; i < path.size(); i++)
        {
            g[path[i][0] - 1].push_back(path[i][1] - 1);
            g[path[i][1] - 1].push_back(path[i][0] - 1);
        }
        vector<int> answer(N, 0); //初始化全部没有染过色
        for (int i = 0; i < N; i++)
        {
            set<int> color{1, 2, 3, 4};
            for (int j = 0; j < g[i].size(); j++)
            {
                color.erase(answer[g[i][j]]); //把已经染过色的去掉
            }
            answer[i] = *(color.begin()); //染色
        }
        return answer;
    }
};
// @lc code=end
