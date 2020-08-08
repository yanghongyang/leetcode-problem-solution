<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-08-08 10:29:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-08 10:39:04
-->

# 题目描述

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。

`1,2,3 → 1,3,2`

`3,2,1 → 1,2,3`

`1,1,5 → 1,5,1`

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点

- 排列（算法）

# 代码

首先，这是一种算法，具体分析在维基上（😓 看不了）。

参见[powcai](https://leetcode-cn.com/u/powcai/)的解答[下一个排列](https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-powcai/)。

[英文解释](https://pic.leetcode-cn.com/4169e8e0c8b4d71d4d32b4f50b09a57c0ea951cb4bdbd16a785d5847959e261f-1556953035922.png)

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;
        for(k = n - 2; k >= 0; k--)
        {
            if(nums[k] < nums[k + 1])
                break;
        }
        if(k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(l = n - 1; l > k; l--)
            {
                if(nums[l] > nums[k])
                    break;
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
```
