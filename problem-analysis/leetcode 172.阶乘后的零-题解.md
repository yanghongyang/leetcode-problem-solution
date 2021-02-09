### 考点
- 数学

### 思路
求 `n!` 中尾数中 `0` 的数量，最直接的想法便是求从 1 到 n 中所有包含 5 这个因子的个数。

**代码1**
```cpp []
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int tmp = i;
            while(tmp % 5 == 0)
            {
                tmp /= 5;
                cnt++;
            }
        }
        return cnt;
    }
};
```
时间复杂度：$O(n)$

空间复杂度：$O(1)$

这种方法过于粗糙，因此寻找高效的方法。

以 n=100 为例，从 1 到 100 一共有 100/5=20 个数字包含 1 个因子 5。除此之外，还有 25 ，50，75，100 这样的数，还包含 1 个因子 5。总共是 20/5=4 个。那么就可以推算出，100! 包含 20 + 4 = 24 个因子 5 。因此答案为 24 。

**代码2**
```cpp []
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n)
        {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};
```
时间复杂度：$O(logn)$

空间复杂度：$O(1)$