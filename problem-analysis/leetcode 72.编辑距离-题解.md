### 考点
- 动态规划
- 编辑距离

### 思路
想把 word1 变成 word2，可以进行三种操作：
1. 插入一个字符
2. 删除一个字符
3. 替换一个字符

看起来这三种操作十分不同，但实际上插入一个字符和删除一个字符在某些程度上可以等价，在 word1 中删掉一个字符，相对于 word2 即为 word2 增加了一个字符。

替换一个字符，言下之意为在某个位置之前，word1 和 word2 的字符都相同。

如果设 dp[i][j] 为 word1 的前 i 个字符转换为 word2 的前 j 个字符所需要的最少操作数，则状态转移方程为：

$$
dp[i][j] = \left\{
    \begin{aligned}
    &dp[i-1][j-1] &&word[i-1]==word[j-1]\\
    &min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1 &&else \end{aligned}
    \right.
$$

可以理解为：
1. 如果 word[i-1] == word[j-1] （如果 word1 的第 i 个元素和 word2 的第 j 个元素相等），则 dp[i][j] = dp[i-1][j-1]（不用进行任何操作，所以操作次数等于这两个单词在此位置之前所进行的操作数）
2. 否则，由于无论如何都要操作了，所以取在此位置之前的三种操作中次数最小的情况，再加一次本次操作。因为要么加，要么减，要么替换，因此肯定能在 1 次操作以内完成。即 `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1`

 
**代码**
```cpp []
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
```

时间复杂度：$O(mn)$，其中 m 为 word2 的长度， n 为 word1 的长度。

空间复杂度：$O(mn)$，主要空间消耗在 dp 数组上。

### 后记
**编辑距离**是非常经典的动态规划题......本科老师讲过，学校OJ出过，算法书上出现过。啊就这样吧。