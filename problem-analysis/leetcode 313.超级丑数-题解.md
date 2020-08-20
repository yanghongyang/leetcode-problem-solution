<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 10:40:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 10:48:28
-->
# [题目描述](https://leetcode-cn.com/problems/super-ugly-number)
编写一段程序来查找第 `n` 个超级丑数。

超级丑数是指其所有质因数都是长度为 `k` 的质数列表 `primes` 中的正整数。
```
示例:
输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
```
```
说明:
1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-ugly-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 动态规划（多指针）

# 题目分析
如果没有做过[丑数](https://leetcode-cn.com/problems/ugly-number/)和[丑数II](https://leetcode-cn.com/problems/ugly-number-ii/)的话，请先完成这两道题。

本题思路和[丑数II](https://leetcode-cn.com/problems/ugly-number-ii/)基本一致。不同点仅在于本题提供了 `primes` 数组，数组长度未定。

那么在循环过程中，可以先设置一个变量 `mini` 保存指针在 `ans` 中的位置对应的值×自身prime值的最小值，接着再循环一次将所有的指针位置进行更新。


# 代码（动态规划）
```cpp
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        vector<int> ans(n);
        vector<int> kv(k, 0); //用来记录这k个数的指针位置，初始化为0
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                mini = min(mini, ans[kv[j]] * primes[j]);
            }
            for (int j = 0; j < k; j++)
            {
                if (mini == ans[kv[j]] * primes[j])
                {
                    kv[j]++;
                }
            }
            ans[i] = mini; //记录下最小值
        }
        return ans[n - 1];
    }
};
```