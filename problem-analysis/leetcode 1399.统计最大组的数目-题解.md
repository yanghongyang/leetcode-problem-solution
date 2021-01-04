<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 14:50:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 14:50:47
-->
#### 考点
- 模拟

#### 思路分析
emmmm......感觉这题没啥好分析的，按照题目的要求来做就好了。朴素简单的想法，分为三个步骤。

步骤 `1` ：计算每个数字的数位和。属于基础中的基础知识点，不再赘述。

步骤 `2` ：使用哈希表（ `unordered_map` ）记录每个数位和出现的次数，并统计其中的最大值（ `maxcnt` ）。

步骤 `3` ：遍历哈希表，如果遍历表项值为最大值，则计数器（代码中的变量名为 `ans` ）加一。

#### 代码
```cpp []
class Solution
{
public:
    int cnt(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> count;
        int maxcnt = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            count[cnt(i)]++;
        }
        for (auto m : count)
        {
            if (maxcnt < m.second)
                maxcnt = m.second;
        }
        for (auto m : count)
        {
            if (maxcnt == m.second)
                ans++;
        }
        return ans;
    }
};
```

#### 后记
头脑简单的我拿到这题立刻就暴力模拟，然后就过了。做完题想了想，是否还有其他更精妙的方法呢？然后了解到其他dalaoes写的动态规划算数位和算法，很不错~~ 还有使用 `vector` 而非 `unordered_map` 来存储数位和的，这种方法的好处在于可以直接用快排对 `vector` 进行排序，直接取最大的几项，也很好~~ 虽然 `unordered_map` 也可以按值排序吧......但这是道题规模不是很大，我想大概也用不了这么精细，于是就没排，直接循环了hhhhhh.......