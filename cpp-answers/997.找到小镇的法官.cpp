/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-19 21:04:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-19 21:08:48
 */
/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        //法官入度为N-1，出度为0
        vector<int> g(N + 1, 0);
        for (auto t : trust)
        {
            --g[t[0]];
            ++g[t[1]];
        }
        for (int i = 1; i <= N; i++)
        {
            if (g[i] == N - 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
