### 考点
- 数学
- 模拟

### 思路
如何做到“有且仅有”，这是本题的难点。当然，由于题目中说了，“如果存在多种答案，你只需实现并返回其中任意一种.”，这就给题目降低了难度，只需要找到一种符合情况的，返回就行了。

观察题目所给要求：` [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] ` 指的是相邻位置的元素的绝对值差，也就是说这是按位置依次计算的，而不是随便计算的。这很重要。

因为要求 "有且仅有 k 个不同整数"，所以可以构造前 `k + 1` 个数的差互不相同，并依次递减到 `1` ，之后的数的差为 `1` 。

可以构造的序列为： `1, k+1, 2, k, 3, k - 1, ......` 。

由此得解。

```cpp []
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n, 0);
        ans[0] = 1;
        int interval = k;
        for (int i = 1; i <= k; i++, interval--)
        {
            if(i & 1)
            {
                ans[i] = ans[i - 1] + interval;
            }
            else 
            {
                ans[i] = ans[i - 1] - interval;
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            ans[i] = i + 1;
        }
        return ans;
    }
};
```

时间复杂度： $O(n)$ 。这里是因为 k 一定小于 n 。

空间复杂度： $O(n)$ ，这里为构建 ans 数组的空间。