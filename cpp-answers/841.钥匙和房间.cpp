/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-31 17:35:50
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-31 17:45:58
 */
/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution
{
public:
    //DFS方法
    //emmmmm总感觉不是很优雅的亚子
    /*     void dfs(vector<vector<int>> &rooms, vector<bool> &vis, int src)
    {
        vis[src] = true;
        for (int i = 0; i < rooms[src].size(); i++)
        {
            if (!vis[rooms[src][i]])
            {
                dfs(rooms, vis, rooms[src][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, vis, 0);
        for (int i = 0; i < rooms.size(); i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    } */
    //改成BFS试试吧，感觉会很优雅
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> vis(rooms.size(), false);
        queue<int> q;
        vis[0] = true;
        for (int i = 0; i < rooms[0].size(); i++)
        {
            q.push(rooms[0][i]);
            vis[rooms[0][i]] = true;
        }
        while (!q.empty())
        {
            int curKey = q.front();
            q.pop();
            for (int i = 0; i < rooms[curKey].size(); i++)
            {
                if (vis[rooms[curKey][i]] == true)
                    continue;
                else
                {
                    vis[rooms[curKey][i]] = true;
                    q.push(rooms[curKey][i]);
                }
            }
        }
        for (int i = 0; i < rooms.size(); i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }
    //emmmmmBFS也不怎么优雅啊......
};
// @lc code=end
