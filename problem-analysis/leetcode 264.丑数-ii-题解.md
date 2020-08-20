<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 09:50:24
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 10:26:15
-->
# [题目描述](https://leetcode-cn.com/problems/ugly-number-ii)
编写一个程序，找出第 `n` 个丑数。

丑数就是质因数只包含 `2, 3, 5` 的正整数。
```
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```
```
说明:  
1 是丑数。
n 不超过1690。
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 堆（思想）
- 动态规划（多指针？？？）
- 模拟

# 题目分析
这道题是`丑数`系列的第二道题。（听说某知名企业 ~~ByteDance~~ 的面试好像考了）

原始思路肯定是**暴力模拟**。从1开始分别×2、×3、×5。每一次操作都比较三个数的大小，依次循环，最后排序，取第`n`个。

这种方法有个弊端，就是要列举的数字实在是太多了。在列举不知道多少个丑数才能是第`n`个丑数的情况下，只能从`1`到`INT_MAX`之间的所有数都进行循环（不够准确，但是应选择1到INT_MAX之间所有以2、3、5为因子的数进行循环）。循环是三重循环，时间复杂度为$O(log^3{INT\_MAX})$。

暴力模拟肯定 **不是最优解**。因此对朴素的暴力方法进行分析，发现可以使用 **堆** 的思想实现一定的优化。

**堆** 思想在实现上借用了 **优先队列** ，因此在解决本题时，首先将`1`入队，接着每次循环将队头元素出队并将队头元素×2、×3、×5的值入队。最终队头元素便是第`n`个丑数。在操作过程中应注意重复元素需要删除。

使用 **堆** 这种方法是一种思路，但也不是最优解。因为每一次队头元素的计算都会打乱之前排好的堆，因此重排堆也需要消耗很多时间。

从前两种方法中可以发现，这两种方法中都涉及到了排序。也就是这两种方法都是先计算所有的结果然后再排序。那么可不可以先计算好当前元素经过×2、×3、×5操作之后的最小值，再将最小值存到它应该在的地方呢？

这种方法是可行的。以这种方法进行模拟实际上相当于维护了一个小顶堆（说法参考自：https://leetcode-cn.com/problems/ugly-number-ii/solution/bao-li-you-xian-dui-lie-xiao-ding-dui-dong-tai-gui/）

要想将最小值存在它应该在的地方，首先需要定义一个大小为`n`的`vector`。最终返回的是`vector`的最后一个元素。

设定 `3` 个指针分别为 `t2` 、 `t3` 、 `t5` 。初始情况下三个指针都指向 `0` 位置。

每一次循环都将 `3` 个指针指向的数组值分别×指针对应的数（2、3、5），接着比较大小。并将其中的最小值存到当前的`vector`数组中。

接着比较最小值到底是从哪里计算而来的，并将对应的位置+1。

姑且将第三种方法称作 **动态规划** 。好处便是循环体内的计算次数有限。极大提高了时间效率。
# 代码（暴力模拟）
```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a = 1;a <= INT_MAX;a *= 2)
            for (long long b = a;b <= INT_MAX;b *= 3)
                for (long long c = b;c <= INT_MAX;c *= 5)
                    v.push_back(c);
        sort(v.begin(),v.end());
        return v.at(n-1);
    }
};
```

# 代码（堆）
```cpp
class Solution {
public:
    int nthUglyNumber(int n)
    {
        priority_queue<double, vector<double>, greater<double>> q;
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        double ans = 1;
        for (int i = 1; i < n; i++)
        {
            q.push(ans * 2);
            q.push(ans * 3);
            q.push(ans * 5);
            ans = q.top();
            q.pop();
            //去掉重复元素
            while (!q.empty() && ans == q.top())
                q.pop();
        }
        return ans;
    }
};
```

# 代码（动态规划/三指针）
```cpp
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; i++)
        {
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
            if (k[i] == k[t2] * 2)
                t2++;
            if (k[i] == k[t3] * 3)
                t3++;
            if (k[i] == k[t5] * 5)
                t5++;
        }
        return k[n - 1];
    }
};
```