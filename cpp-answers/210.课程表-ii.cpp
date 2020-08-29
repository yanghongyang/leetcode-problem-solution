/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-29 16:57:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-29 17:20:12
 */
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
/* class Solution
{
public:
    //拓扑排序
    //存储有向图
    vector<vector<int>> edges;
    //标记每个节点的状态，0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    //用数组来模拟栈，下标0为栈底，下标n-1为栈顶
    vector<int> result;
    //判断有向图中是否有环
    bool valid = true;
    void dfs(int u)
    {
        //将节点标记为[搜索中]
        visited[u] = 1;
        //搜索其相邻节点，只要有环，立刻停止搜索
        for (int v : edges[u])
        {
            //如果[未搜索]，那么搜索相邻节点
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                    return;
            }
            //如果[搜索中]，则说明找到了环
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        //将节点标记为[已完成]
        visited[u] = 2;
        //将节点入栈
        result.push_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        //每次挑选一个[未搜索]的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
                dfs(i);
        }
        if (!valid)
            return {};
        //如果没有环，那么就有拓扑排序
        //注意下标0为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
}; */
class Solution
{
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]]++;
        }
        queue<int> q;
        //将所有入度为0的节点放入队列中
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            //从队首取一个节点
            int u = q.front();
            q.pop();
            //放入答案中
            result.push_back(u);
            for (int v : edges[u])
            {
                indeg[v]--;
                //如果相邻节点v的入度为0，就可以选v对应的课程了
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        if (result.size() != numCourses)
            return {};
        return result;
    }
};
// @lc code=end
