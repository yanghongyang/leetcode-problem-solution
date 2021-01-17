#### 考点
- 深度优先搜索
- 并查集

#### 思路
这题的一个点在于： **一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。** 这就给题目降低了难度，即砖块如果被消除，或者掉落，值都会在二元网格上变为 `0` ，而不是让掉落的砖块掉到其他稳定的砖块上。

题目还有一个点：**`hits` 是需要依次消除砖块的位置。** 这提示我们，如果不按照给定的顺序消除砖块，那么 `result[i]` 是得不到正确的解的。

一种显而易见的思路便是每一次 `hit` 都更新整张图，然后对每个砖块进行状态更新。这种方法会超时。具体分析见：[【DFS】超过 100% (803. 打砖块)](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/dfs-chao-guo-100-803-da-zhuan-kuai-by-fe-a1j1/) 。

接下来的思路来源自官方题解和其他各种题解（参见 **代码及思路参考** ）

`掉落砖块的数目=击碎砖块之前与屋顶相连的砖块数目-击碎砖块之后与屋顶相连的砖块数目 - 1` 。

这个 `1` 表示击碎的砖块本身。

总体思路为：

1. 移除 `hits` 对应的砖块（ `grid[i][j]--` ）。这样做的效果是有一些位置的砖块处于“悬空”状态。
2. 把 `grid` 数组中与顶部相连的砖块进行标记，并记录此时每个与顶部相连的砖块所形成的连通域的大小。这样以后 `grid` 数组的值实际上有三种：`2` 表示与顶部相连，`1` 表示悬空，`0` 表示被击碎， `-1` 表示原先没有砖块（`hit` 数组没有说明一定会达到砖块，很可能打到了没有砖块的地方）。
3. 把 `hit` 数组倒序加回到 `grid` 数组中，并进行判断。判断 `hit` 的当前砖块加上之后是否和顶部相连，如果与顶部相连，则对当前砖块的四周进行遍历，对与它相连的砖块进行标记，并记录这个时候和它相连的值为 `1` 的砖块的个数 `ans` 。
4. 结果就是 `ans - 1` 。 


**代码1：外网的DFS解法，这里用 `C++` 进行了重写**
```cpp []
class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &m)
    {
        if (i < 0 || i >= m.size() || j < 0 || j >= m[0].size() || m[i][j] != 1)
            return 0;
        m[i][j] = 2;
        return dfs(i + 1, j, m) + dfs(i - 1, j, m) + dfs(i, j + 1, m) + dfs(i, j - 1, m) + 1; //统计与其相连的砖块的个数
    }
    bool isConnected(int x, int y, vector<vector<int>> &m)
    {
        if (x == 0) //要打的砖块位于顶部，肯定相连
            return true;
        for (auto d : direction)
        {
            int xt = x + d[0];
            int yt = y + d[1];
            if (xt >= 0 && xt < m.size() && yt >= 0 && yt < m[0].size() && m[xt][yt] == 2)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int n = hits.size();
        vector<int> res(n, 0);
        vector<vector<int>> m = grid;
        for (auto h : hits)
        {
            m[h[0]][h[1]]--; //移走所有hits位置的砖块
        }
        //然后把所有与top相连的标记为2
        for (int i = 0; i < grid[0].size(); i++)
        {
            dfs(0, i, m);
        }
        //然后再把已经击中的砖头加回去
        for (int i = n - 1; i >= 0; i--)
        {
            int x = hits[i][0], y = hits[i][1];
            m[x][y]++;
            //如果加回去为1，则原来m[x][y]这个地方有砖块
            //在有砖块的情况下，如果与顶部相连，则以(x,y)这个位置为起点做dfs，记录与它相连的砖块个数
            if (m[x][y] == 1 && isConnected(x, y, m))
            {
                res[i] = dfs(x, y, m) - 1;
            }
        }
        return res;
    }

private:
    int TOP = 2;
    int BRICK = 1;
    int EMPTY = 0;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
```

时间复杂度：暂时不会。

~~O(grid数组的规模+hits数组的规模) 。这里的分析在于，`grid` 数组的每一个元素在使用 `dfs` 进行遍历，把所有与 `top` 相连的标记为 `2` 的时候，都被遍历了一次。除此之外，对于 `hit` 数组中的元素，首先要全部移除，之后又重新加到 `grid` 数组中。因此也需要时间。~~

空间复杂度：$O(grid数组的规模)$ 。由于使用了 `m` 拷贝 `grid` 数组，因此空间复杂度为 `grid` 数组的规模。除此之外，正如 [力扣加加](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/dfs-chao-guo-100-803-da-zhuan-kuai-by-fe-a1j1/) 的分析，递归深度也不会超过整个 `grid` 数组的规模。因此空间复杂度为 $O(grid数组的规模)$

使用类似的思路，可以通过并查集来实现。参考官方题解。

**代码2：并查集，源自官方题解**
```cpp []
class UnionFind
{
private:
    vector<int> parent, sz; //parent为节点的父节点，sz为整个连通域的大小
public:
    UnionFind(int n) : parent(n), sz(n)
    {
        //初始情况下每个节点的parent都是它本身，并且对应的连通域的大小都为1
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) //路径压缩找父亲
    {
        if (parent[x] == x)
            return x;
        else
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy) //如果不是一个父节点，则合并，并且更新父节点所在的连通域的大小
        {
            parent[fx] = fy;
            sz[fy] += sz[fx];
        }
        else
            return;
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};
class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int h = grid.size(), w = grid[0].size(); //h为二维网格的高，w为二维网格的宽
        int n = hits.size();
        vector<int> res(n, 0);
        UnionFind uf(h * w + 1); //二维转一维，计算方法与计算二维数组中元素的物理位置类似
        //第一步：拷贝数组并且移除hit中的砖块
        vector<vector<int>> m = grid;
        for (auto h : hits)
        {
            m[h[0]][h[1]] = 0; //移走所有hits位置的砖块
        }
        //这样以后就只剩下悬停的砖块和顶部相连的砖块了
        //对这些剩下的砖块进行并查集操作，形成一个又一个连通域
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (m[i][j] == 1) //如果m[i][j]=1，则说明可能是悬停砖块或者与顶部相连的砖块
                {
                    if (i == 0) //如果是顶部的砖块
                    {
                        uf.merge(h * w, j);
                    }
                    if (i > 0 && m[i - 1][j] == 1)
                    { //如果和正上方砖块相连
                        uf.merge(i * w + j, (i - 1) * w + j);
                    }
                    if (j > 0 && m[i][j - 1] == 1)
                    { //如果和正左边砖块相连
                        uf.merge(i * w + j, i * w + j - 1);
                    }
                }
            }
        }
        //然后再把已经击中的砖头加回去
        for (int i = n - 1; i >= 0; i--)
        {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) //如果原先就没有砖块
                continue;
            int prev = uf.size(h * w); //原先顶部砖块形成的连通域的大小
            if (x == 0)
            {
                uf.merge(y, h * w); //如果击碎的砖块是顶部，则加上之后就与原先的顶部砖块形成的连通域合并
            }
            for (int i = 0; i < 4; i++)
            {
                int xt = direction[i][0] + x;
                int yt = direction[i][1] + y;
                if (xt >= 0 && xt < h && yt >= 0 && yt < w)
                {
                    if (m[xt][yt] == 1) //如果存在砖块
                    {
                        uf.merge(x * w + y, xt * w + yt); //更新连通域
                    }
                }
            }
            int sz = uf.size(h * w); //此时顶部连通域的大小
            res[i] = max(0, sz - prev - 1);
            m[x][y] = 1; //倒序还原砖块
        }
        return res;
    }

private:
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
```
时间复杂度：$O(n\cdot hw \cdot \log(hw))$，其中 `n` 为消除砖块的次数（即数组 $\textit{hits}$ 的长度），`h` 和 `w` 分别为矩阵的行数和列数。图中共有 `h*w+1` 个节点，故并查集的单次操作的时间复杂度为 $O(hw \cdot \log(hw))$。

空间复杂度：$O(hw)$。

以上时空复杂度分析来自另一份[官方题解](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/da-zhuan-kuai-by-leetcode-solution-szrq/)。

#### 代码及思路参考
1. [JAVA Simple DFS 16ms, reversely add bricks back](https://leetcode.com/problems/bricks-falling-when-hit/discuss/141229/JAVA-Simple-DFS-16ms-reversely-add-bricks-back)
2. [官方题解(有视频讲解的那个，特别推荐视频讲解)](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/803-da-zhuan-kuai-by-leetcode-r5kf/)
3. [打砖块：优先队列解法](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/da-zhuan-kuai-you-xian-dui-lie-jie-fa-by-pmey/) 这个还没来得及消化。Mark。
4. [【DFS】超过 100% (803. 打砖块)](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/dfs-chao-guo-100-803-da-zhuan-kuai-by-fe-a1j1/)）

    向写出优先队列解法的大佬和其他所有大佬低头.jpg

#### 后记
这道题作为 `2021` 年 `1` 月 `16` 号的每日一题，被当天浑水摸鱼一整天的我直接 `Ctrl+C` `Ctrl+V` 交了...... 一看就是超级麻烦还难的题，看都没看思路分析就直接复制了别人家的代码混了 `10` 积分......属实不应该。

对这种行为感到非常愧疚，于是在第二天重新做了这道题。啊不能说是做，应该说是，认真地抄？因为没有思路......（额也不能说是没有思路吧，一开始是想暴力求解的，每次hit之后就更新全部的图......但感觉会 `tle` 于是索性就不写了。事实证明确实会 `tle` ，参考：[【DFS】超过 100% (803. 打砖块)](https://leetcode-cn.com/problems/bricks-falling-when-hit/solution/dfs-chao-guo-100-803-da-zhuan-kuai-by-fe-a1j1/)）写下了这篇题解来记录一下这道题。

虽说官方题解指出，并查集不能把一分为二，所以要倒序。但说实话我还是不明白这思路到底是怎么搞的，估计做题做多了就能有这种感觉了吧......不过在思绪乱飞的时候，我想起了 **关节点** 这个概念。感觉和打砖块挺像的......?

题目是非常棒的（逆序思维求解就是真的没想到）。希望能及时复习。

另：为什么 `vscode` 插件上对这题的 `Tags` 有 `dynamic programming` 呢......这也太误导人了，百思不得其解。