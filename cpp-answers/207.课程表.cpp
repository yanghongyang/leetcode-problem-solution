/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
//考察拓扑排序
//可以使用DFS或者BFS
class Solution
{
public:
    //BFS
    /* bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int m = prerequisites.size();
        vector<int> vec1(numCourses, 0);      //存储入度
        vector<vector<int>> vec2(numCourses); //存储每个课程的邻接节点
        for (vector<int> pre : prerequisites)
        {
            vec1[pre[1]]++;
            vec2[pre[0]].push_back(pre[1]);
        }
        //广搜
        queue<int> q;
        //入队入度为0的节点
        for (int i = 0; i < numCourses; i++)
        {
            if (vec1[i] == 0)
                q.push(i);
        }
        int cnt = 0; //用来计数遍历到的节点
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                int cur = q.front();
                q.pop();
                cnt++;
                for (int course : vec2[cur])
                {
                    if (--vec1[course] == 0)
                        q.push(course);
                }
            }
        }
        return cnt == numCourses;
    } */
    //DFS
    bool dfs(int x, vector<int> &vis, vector<vector<int>> &ans)
    {
        vis[x] = 0; //表示当前节点已经访问过了
        bool ret = true;
        for (auto v : ans[x])
        {
            if (vis[v] == 0)
                return false;
            if (vis[v] == -1)
                ret = ret && dfs(v, vis, ans);
        }
        vis[x] = -1; //表示以这个点出发的所有点已经遍历完了。
        return ret;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> ans(numCourses, vector<int>());
        vector<int> vis(numCourses, -1); //判断是否访问过，初始化为-1，即没有访问过
        for (auto v : prerequisites)
        {
            ans[v[1]].push_back(v[0]);
        }
        bool ret = true;
        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == -1)
                ret = ret && dfs(i, vis, ans);
        }
        return ret;
    }
};
// @lc code=end
