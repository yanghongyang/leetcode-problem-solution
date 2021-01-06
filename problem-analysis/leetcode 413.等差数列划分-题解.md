<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-06 11:06:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-06 12:18:24
-->

#### 考点
- 暴力
- 动态规划

#### 思路分析1 暴力

拿到这题，让求“个数”，并且等差数列是有章可循（A[i - 2] - A[i - 1] == A[i - 1] - A[i]）的，因此首先想到的便是动态规划。

然而应该怎么找到子问题呢？这就成了一个解题时的瓶颈。于是便先用暴力法写了。

暴力方法比较好想，只需要两层遍历数组，并在内循环对是否为等差数组进行比较即可。

**代码**
```cpp []
int numberOfArithmeticSlices(vector<int> &A)
{
    int cnt = 0;
    if (A.size() <= 2)
        return 0;
    for (int i = 0; i < A.size() - 2; i++)
    {
        int d = A[i + 1] - A[i];
        for (int j = i + 2; j < A.size(); j++)
        {
            if (A[j] - A[j - 1] == d)
                cnt++;
            else
                break;
        }
    }
    return cnt;
}
```

时间复杂度：$O(N^2)$

空间复杂度：$O(1)$

#### 思路分析2 动态规划
这类题目（求“个数”）最好的方法肯定是寻找到状态转移方程，然后求解。而私以为找到状态转移方程的前提在于，赋给 `dp[]` 数组什么意义。

如果设置 `dp[i]` 为以第 `i` 个元素为结尾所能构成的等差子数组的数量，则 `dp[i - 1]` 表示以第 `i - 1` 个元素为结尾所能构成的等差子数组的数量。这两者实际上没有什么关系，因为`dp[i - 1]` 中可能包含着不以 `A[i - 1]` 为结尾的等差子数组，如此一来即便 `A[i] A[i - 1] A[i - 2]` 构成了等差数列，也不能推出任何的关系。因此不能赋予 `dp[i]` 这样的意义。

本题的“等差数列”这个条件，实际上可以写成 `"A[i - 2] - A[i - 1] == A[i - 1] - A[i]"` ，假设从 `A[k...i - 1]` 都是等差数列，那么其中的任意子数列都是等差子数列。此时如果遍历到第 `i` 个元素，也满足等差数列的关系，则 `A[k...i]` 也构成等差数列，那么其中任意的子数列也都是等差子数列。由第 `i-1` 个元素扩展到第 `i` 个元素，从 `A[k]` 开始的能够构成等差子数列的数目，实际上 **增加** 了 ( **`A[k...i-1]` 所能构成的等差子数列的数目 + 1** (由 `A[i - 2] A[i - 1] A[i]` 所构成的等差数列))个，因此可以赋予 `dp[i]` 的含义，即为这个增量。

那么状态转移方程可以写作：

$$
dp[i] = \begin{cases}dp[i - 1] + 1& &{dp[i - 2] - dp[i - 1] == dp[i - 1] - dp[i]} \\
0& &{ other} \end{cases}
$$

有了状态转移方程，即可写出代码。

**代码**
```cpp []
int numberOfArithmeticSlices(vector<int> &A)
{
    int cnt = 0;
    if (A.size() <= 2)
        return 0;
    vector<int> dp(A.size(), 0); //dp[i]：如果在前i-1个数之后添上A[i]，能够构成等差子数组的增量）。
    for (int i = 2; i < A.size(); i++)
    {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
            cnt += dp[i]; //每次更新总次数
        }
    }
    return cnt;
}
```

时间复杂度：$O(N)$

空间复杂度：$O(N)$

以上的代码可以称为动态规划的朴素版本，因为可以将空间复杂度进一步降低，使用整型变量代替 `vector` 即可。(emmmm原理类似求解斐波那契数列的第n个数？)

**代码**
```cpp []
int numberOfArithmeticSlices(vector<int> &A)
{
    int cnt = 0;
    if (A.size() <= 2)
        return 0;
    int dp = 0;
    for (int i = 2; i < A.size(); i++)
    {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        {
            dp = dp + 1;
            cnt += dp; //每次更新总次数
        }
        else
        {
            dp = 0;
        }
    }
    return cnt;
}
```

时间复杂度：$O(N)$

空间复杂度：$O(1)$

#### 思路分析3 双指针
这个思路来源自 思路分析1 和其他同伴的题解。本题中暴力法的基本思想是对每一个元素进行遍历，那么可不可以减少这种遍历呢？因为等差子数列存在着一定的关系，即如果 `A[k...i - 1]` 是等差数列，`A[i - 2] A[i - 1] A[i]` 也是等差数列，实际上 `A[k...i]` 也能构成等差数列。

那么可以考虑一下双指针的方法。 使用 `ans` 来记录个数， `left` 和 `right` 分别表示左右两个指针。 `left` 指针指向 `k` 所在的位置（初始为 `0` ），然后 `right` 指针（初始为 `2` ）向右滑动，只要 ` A[right - 2] A[right - 1] A[right]` 构成等差数列， `ans` 就更新( `ans += right - left - 1` ，可以理解为：增量为 (right - 2) - left + 1) ， `right` 就继续向右。 如果不能构成等差数列，则更新 `left ( left = (right - 2) + 1 )` 和 `right (right = right + 1)` ，这样一直操作直到遍历结束。

**代码**
``` cpp []
int numberOfArithmeticSlices(vector<int> &A)
{
    int ans = 0;
    int left = 0, right = 2;
    if (A.size() < 2)
        return ans;
    while (right < A.size())
    {
        if (A[right] - A[right - 1] == A[right - 1] - A[right - 2])
        {
            ans += (right - left - 1);
            right++;
        }
        else
        {
            left = right - 1;
            right++;
        }
    }
    return ans;
}
```

时间复杂度：$O(N)$

空间复杂度：$O(1)$

#### 后记
这题应该曾经出现过某校的 `OJ` 上。应该是属于经典题啦。