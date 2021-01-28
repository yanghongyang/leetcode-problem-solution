#### 思路
- 模拟
- 前缀和

#### 题目分析
题目要求寻找到 **中心索引**。根据中心索引的定义，假设第 `i` 个数为 中心索引，其左边的和为 `left` ，其右边的和为 `right` ，则 `left == right` 。

除此之外，假设数组所有元素的和为 `total` ，则上式可以表示为 `total == left + right + nums[i]` ，把 `left` 记为 `sum` ，则中心索引的判断表达式为：

$$sum \times 2 + nums[i] == total$$

由此可遍历整个数组，对其中每一个元素进行判断。

#### 代码
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(sum * 2 + nums[i] == total)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};
```

时间复杂度：$O(n)$，其中 `n` 为数组 `nums` 的长度。
空间复杂度：$O(1)$，使用辅助常数变量。
