<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-07 09:43:59
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-07 10:31:53
-->

#### 考点
- 求连通分量

#### 方法
- 深度优先搜索
- 广度优先搜索
- **并查集**

#### 思路
这道题是一道经典的图论问题，求连通分量。拿到这题最经典的方法就属 **并查集** 了。但使用深度优先搜索和广度优先搜索也可以实现相同的功能。在使用深搜和广搜时只需要设置 `visited` 数组来记录点是否被访问过即可。

**代码：深度优先搜索**
```cpp []
class Solution
{
public:
    void dfs(vector<vector<int>> &M, vector<bool> &visited, int i)
    {
        visited[i] = 1;
        for (int j = 0; j < M.size(); j++)
        {
            if (i != j && M[i][j] && !visited[j])
            {
                dfs(M, visited, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(M, visited, i);
                cnt++;
            }
        }
        return cnt;
    }
};
```
时间复杂度：$O(N^2)$，这里的分析为，对于 `M` 中的 `N` 个点进行遍历，尽管在每次遍历时都需要调用 `dfs` 递归函数进行处理，但是对于递归函数而言，最坏情况不过是对与第 `i` 个点相连的所有点进行遍历。因此最坏情况不会超过 `N` ，所以总体的时间复杂度为 `O(N^2)` 。（从另一个角度来看，未被标记为 `visited` 的点将只有一次被遍历到，而这次遍历将会改变其 `visited` 状态，整个图有 $N^2$ 个点，因此时间复杂度为 $O(N^2)$ 。

空间复杂度：$O(N)$ ，为 `visited` 向量的规模。

在使用 `DFS` 解题时，一定要注意 `DFS` 函数的传参问题！比如说本题代码中的 `visited` 向量，在一开始实现的时候忘记传引用了，于是导致了错误。这种细微的错误就是很难排查到。

**代码：广度优先搜索**
```cpp []
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int t = q.front();
                    q.pop();
                    visited[t] = 1;
                    for (int j = 0; j < n; j++)
                    {
                        if (t != j && M[t][j] && !visited[j])
                        {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
```
时间复杂度：$O(N^2)$，这里的分析为，遍历图M的所有点，即为 $N^2$ 。

空间复杂度：$O(N)$，为队列 `Queue` 的规模。最坏情况下队列的规模为与 `i` 点相连的所有点，因此空间复杂度为 $O(N)$ 。

一般来讲用深度优先搜索能够实现的题目，用广度优先搜索也能做。但感觉上就是有一点奇奇怪怪的。

#### 并查集
这类题目最经典的方法就是并查集了。顾名思义，并查集的操作分为 “查” 和 “并” ，“集” 表示通过前两个操作，可以将原本孤立的点变成一个集合。以上仅代表个人观点。

对于每一个节点，定义其父亲节点 `parent` 。初始情况下各个节点的父亲节点指向其自身。当我们遍历图的邻接矩阵（或者其他可以表示点之间连接关系的数据结构）时，如果两个点之间相连，则将一个节点的父亲节点设置为另一个节点的父亲（也就是 “并” 的操作，即两个节点拥有共同的祖先）。这一步首先需要查找两个节点各自的父亲节点，如果相同则说明节点处于同一个连通分量，否则将把一个节点的父亲节点设置为另一个节点的父亲节点。当然对于这步操作有多种优化方法（【按秩合并】和【路径压缩】，参见《算法》第4版 1.5节，原理归结起来大概可以为 **优化并缩短树高** ）。

有关于并查集的相关讨论，可以参考：

1. bilibili/coursera Prinston大学教授讲解的 *Algorithm (4th edition)*，第一讲
2. 想简单了解下的朋友可以看：[借这个问题科普一下并查集各种情况下的时间复杂度](https://leetcode-cn.com/problems/number-of-provinces/solution/jie-zhe-ge-wen-ti-ke-pu-yi-xia-bing-cha-0unne/)
3. [并查集](https://ojeveryday.github.io/AlgoWiki/#/UnionFind/01-introduction)，讲的很细致（点个赞）

**代码：并查集**
```cpp []
class Solution
{
public:
    int find(vector<int> &parent, int n)
    {
        return parent[n] == n ? n : find(parent, parent[n]);
    }
    void Union(vector<int> &parent, int m, int n)
    {
        int pm = find(parent, m);
        int pn = find(parent, n);
        if (pm != pn)
        {
            parent[pm] = pn;
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int cnt = 0;
        int n = M.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] && i != j)
                {
                    Union(parent, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};
```
时间复杂度：$O(N^2 logN)$，对于图的邻接矩阵的每一个点都进行 `Union` 操作，而 `Union` 的时间复杂度为 $O(logN)$ （正比于连通路径的长度）。

空间复杂度：$O(N)$，为 `parent` 向量的规模。

#### 后记
写题解最大的好处莫过于发现自己的语言表达能力非常欠缺，亟待提高。就和英文翻译一样，即便脑袋理解了，说出来写下来又是另一回事儿了。

**并查集** 实际上是普林斯顿大学开设的《算法》课程的老教授讲的第一讲。要问我为啥这么清楚，每次想学算法的时候打开视频，讲的就是这个。没毅力的我看视频总是只看第一讲的哈哈哈哈。

**深度优先搜索** 和 **广度优先搜索** 的思想来源于邓俊辉老师的《数据结构（C++语言版）》，在讲解图论的时候讲了 **DFS** 和 **BFS** 的应用（双连通域分解），虽然没怎么看明白，不过当时就觉得这两种算法也肯定可以用于求解连通域相关的问题。

对于时间复杂度和空间复杂度的分析，属实为个人拙见，望各位不吝赐教。
