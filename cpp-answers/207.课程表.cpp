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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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
    }
};
// @lc code=end
