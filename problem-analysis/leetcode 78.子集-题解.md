<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-08-22 12:30:21
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-22 12:47:54
-->

# [题目描述]()

给定一组不含重复元素的整数数组  `nums`，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

```
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点（解题方向）

- 回溯
- 迭代
- 位运算（hashmap 思想）

# 题目分析

这道题乍一看和[全排列](https://leetcode-cn.com/problems/permutations/)很相似，只不过全排列要求元素个数必须和集合里的元素相同，而子集中元素的个数可以从 `0` 到集合的长度。因此很容易想到 **回溯** 和 **迭代** 两种方法。

在实现 **回溯** 算法的时候，注意边界判断。~~其他没啥好说的直接写就过了。~~

在实现 **迭代** 算法的时候，思路为：对于 `nums` 中的元素来讲，都可以在当前的所有子集中加上 `nums` 该元素，接着每次迭代都不断更新当前 `res` 的长度。~~还是看代码最直接了，将不太能讲清楚。~~

**位运算** 方法基于 **hashmap** 思想。可以将集合中的每个元素看成一个数位。如果数位上的值为 `1` 则说明该位置的元素在子集中。除此之外，根据数学知识可得 `n` 个不同元素构成的集合，其子集个数为 $2^n$ 个。因此在初始化时可以直接设定答案 `res` 的长度为 $2^{nums.size()}$ 。

# 代码（回溯）

```cpp
void dfs(vector<vector<int>> &res, int i, vector<int> &tmp, vector<int> &nums, int n)
{
    if (i > n)
        return;
    res.push_back(tmp);
    for (int j = i; j < n; j++)
    {
        tmp.push_back(nums[j]);
        dfs(res, j + 1, tmp, nums, n);
        tmp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(res, 0, tmp, nums, nums.size());
    return res;
}
```

# 代码（迭代）

```cpp
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res = {{}};
    for (int num : nums)
    {
        int n = res.size();
        for (int i = 0; i < n; i++)
        {
            res.push_back(res[i]);
            res.back().push_back(num);
        }
    }
    return res;
}
```

# 代码（位运算）

```cpp
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int p = 1 << n;
    vector<vector<int>> res(p);
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                res[i].push_back(nums[j]);
            }
        }
    }
    return res;
}
```

对于本方法，最重要的一句代码莫过于：

```cpp
if ((i >> j) & 1)
```

对这一句代码的解释如下：

已知 `i` 的值为从 $0$ 到 $2^n-1$，因此每一个 `i` 的二进制表示的每一个位置就代表 `nums` 上的对应位置的数字是否取了。

因此 `(i >> j) & 1` 代表 `i` 的第 `j` 个位置上的数字是否为 `1`。

如果为 `1` ，则需要把 `nums[j]` 压入 `res` 数组中。
