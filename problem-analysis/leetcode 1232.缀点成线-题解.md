#### 考点
- 数学

#### 思路分析
这题最明显的思路便是求斜率了。斜率的计算方式为：`k=(y1-y2)/(x1-x2)` ，其中点 `P1` 的坐标为 `(x1, y1)` ，点 `P2` 的坐标为 `(x2, y2)` 。

那么只要比较给出点的斜率是否相同就可以了。

但这里有两个问题：

1. 如果斜率不存在的话，是没办法做除法的。
2. `C++` 的 `double` 类型（除法运算得出的结果存在 `double` 类型变量里）比较起来十分麻烦，由于误差原因，不能直接进行相等比较。

为了解决这两个问题，可以将连续三个点的斜率计算转换为乘法。

假设 `P1(x1, y1), P2(x2, y2), P3(x3, y3) (x1 <= x2, x2 <= x3, y1 <= y2, y2 <= y3)` ，那么判断这三个点是否在一条线上的条件为： `(y1-y2)*(x2-x3) == (x1-x2)*(y2-y3)`

为了方便运算，可以先对给定的点进行排序。（以横坐标为第一优先，纵坐标为第二优先，从小到大排序）

#### 代码
```cpp []
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 0)
            return false;
        sort(coordinates.begin(), coordinates.end(), cmp);
        int n = coordinates.size();
        for(int i = 1; i < n - 1; i++)
        {
            if((coordinates[i][0] - coordinates[i - 1][0]) * (coordinates[i + 1][1] - coordinates[i][1]) != (coordinates[i][1] - coordinates[i - 1][1]) * (coordinates[i + 1][0] - coordinates[i][0]))
            {
                return false;
            }
        }
        return true;
    }
};
```

时间复杂度： $O(nlogn)$ ，此处理解为，在排序过程中使用快速排序，消耗时间复杂度为 $O(nlogn)$， 其中 `n` 为 `coordinates` 数组中元素的个数。除此之外，排好序要使用一次遍历进行判断比较，因此时间复杂度为 $O(n)$。

空间复杂度：$O(1)$ ，只使用了常数级别的变量进行记录和循环。

如果时空复杂度分析有误，恳请各位大哥指正！