#### 考点
- 深度优先搜索（DFS）


#### 题目分析
首先这题是一道地图类型的题目。也就是说如果要解这样的问题，必须得把点给遍历一遍。......

额，编不下去了。这题就是典型的深搜/广搜题。

可以设置两个变量，分别记录从当前点是否可以到达太平洋/大西洋。在 `DFS` 的时候可以用剪枝来缩短点时间。


**代码：朴素的DFS**
```cpp []
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &matrix, bool &reachP, bool &reachA)
    {
        if (matrix[i][j] == -1 || (reachP && reachA))
            return; //如果已经遍历过了，或者已经满足条件了，就直接返回
        int tmp = matrix[i][j];
        matrix[i][j] = -1; //标记已经访问过了
        for (int k = 0; k < 4; k++)
        {
            int tx = i + direction[k][0], ty = j + direction[k][1]; //四个方向遍历
            if (tx < 0 || ty < 0)                                   //如果到达右上角
            {
                reachP = true;
            }
            else if (tx == matrix.size() || ty == matrix[0].size())
            {
                reachA = true;
            }
            else if (matrix[tx][ty] <= tmp)
            {
                dfs(tx, ty, matrix, reachP, reachA);
            }
        }
        matrix[i][j] = tmp; //恢复状态
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> res;
        if (matrix.size() <= 0)
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                bool reachP = false; //能否到达太平洋，默认为false
                bool reachA = false; //能否到达大西洋，默认为false
                dfs(i, j, matrix, reachP, reachA);
                if (reachP && reachA)
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
```

尝试分析下时空复杂度......

时间复杂度：$O(m^2*n^2)$ 。这里我的理解是对于 `matrix` 中的每个点都做一次 `dfs` 遍历。而在每一次 `dfs` 遍历时，都会递归调用遍历其他点。

空间复杂度：$O(m*n)$。 这里我的理解是从递归深度的角度来考虑。最大递归深度为整张图的规模。

属实不怎么会分析时空复杂度，如果错了的话希望朋友们不吝赐教。

#### 后记
虽说题目不难，但还是卡了好久。最后发现是外循环的变量和内循环的变量重名了......发现错误的时候已经过了快 `1h`......属实是阴沟里翻船。 