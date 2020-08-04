# 题目描述
你这个学期必须选修 `numCourse` 门课程，记为`0` 到 `numCourse-1` 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 `0` ，你需要先完成课程 `1` ，我们用一个匹配来表示他们：`[0,1]`

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

**示例 1:**

```
输入: 2, [[1,0]] 

输出: true

解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
```

**示例 2:**
```
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
```

**提示：**

输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。

详情请参见图的表示法。

你可以假定输入的先决条件中没有重复的边。

`1 <= numCourses <= 10^5`

# 考点
- 拓扑排序
- 深度搜索/广度搜索
- 并查集

# 题目分析
这道题是有关图的拓扑排序的经典问题。也可以用另一种方式来进行表述，即：**给你一个有向图，求问其中有没有环**。

对于本题来讲，如果有环路，则返回`false`；否则返回`true`。

如何判断图中是否有环路呢？有三种方式判断：
1. 广度优先搜索（BFS）
2. 深度优先搜索（DFS）

下面针对每一种方式给出相应的解法。摘自若干位dalao的博客和代码。

# 方法一：广度优先搜索
想要使用广度优先搜索判断图中是否有环，需要统计图中每个节点的入度和出度。

首先将入度为0的节点入队列。接着使用广度优先搜索，将该点指向的节点（即相邻节点）的入度-1，判断此时相邻节点的入度是否为0。如果为0，则入队。依次循环，直到队列为空。

每一次节点入队，统计次数cnt+1，如果最终cnt==课程的数目，则图中不存在环路。

这种算法中需要体会：
1. 首先将入度为0的节点入队列。因为入度为0的节点意味着不需要先修课程。
2. 将入度为0的节点a入队列之后，将a指向的节点的入度-1。这意味着以a为先修课的课程们可以不用选这门课了。
3. 判断此时这些相邻节点的度数，将入度为0的节点入队。这意味着只以a为先修课的课程们现在不需要a就可以上课了（做一个模拟，因为a已经入队了）。
4. 依次循环，可以判断图中是否存在环。也就是有没有存在a->b, b->c, c->a的情况。

**代码**
```
//BFS
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
```

# 方法二：深度优先搜索
使用深度优先搜索来判断图中有没有环，只需要沿着某一个节点深度搜索，判断在搜索的过程中是否出现它本身即可。

对图中的节点访问情况，分为-1（即没有访问过）、0（访问过）两种情况，每一次dfs的时候先把节点设为0，在dfs之后再恢复-1的状态。

**代码：**
```
class Solution
{
public:
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
```

当然官方题解里提到的三种状态也很方便！而上方的代码抄自[C++,拓扑排序+DFS](https://leetcode-cn.com/problems/course-schedule/solution/ctuo-bu-pai-xu-dfs-by-zb121/)。