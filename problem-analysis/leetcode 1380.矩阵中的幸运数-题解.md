<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 14:15:18
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 14:22:01
-->
#### 考点
- 模拟

#### 题目分析
这题是赤裸裸的模拟题。有两种思路可供参考。

#### 思路1
先求出每一行的最小值所在的位置，然后对于每一行的最小值，判断其是否为对应的列的最大值。

**代码**
```cpp []
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    unordered_map<int, int> rowmini;
    for (int i = 0; i < m; i++)
    {
        int tmp = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (tmp > matrix[i][j])
            {
                tmp = matrix[i][j];
                rowmini[i] = j;
            }
        }
    }
    for (auto rm : rowmini)
    {
        int col = rm.second;
        int tmp = matrix[rm.first][rm.second];
        bool flag = true;
        for (int i = 0; i < m; i++)
        {
            if (tmp < matrix[i][col])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(matrix[rm.first][rm.second]);
        }
    }
    return ans;
}
```

#### 思路2
针对每一个元素 `matrix[i][j]` ，判断其是否为所在行的最小值以及所在列的最大值。如果是，则更新行最小值所在位置 （ `rowmin[i]` ）/列最大值所在位置（ `colmax[j]` ）。接着再对每一个元素进行遍历，如果 `matrix[i][j] == rowmin[i] && matrix[i][j] == colmax[j]` 则符合题意。

**代码**
```cpp []
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> rmin(m, INT_MAX);
    vector<int> cmax(n, INT_MIN);
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rmin[i] = min(rmin[i], matrix[i][j]);
            cmax[j] = max(cmax[j], matrix[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j])
                ans.push_back(matrix[i][j]);
        }
    }
    return ans;
}
```
