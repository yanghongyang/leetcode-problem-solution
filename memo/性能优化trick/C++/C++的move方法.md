<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-10 17:34:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-10 18:05:47
-->
#### 简介


#### 用法
参见[Leetcode 228.汇总区间 官方题解](https://leetcode-cn.com/problems/summary-ranges/solution/hui-zong-qu-jian-by-leetcode-solution-6zrs/)

题目本身不算难，官方题解的代码也很简洁。

**官方题解的代码**
```cpp []
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/summary-ranges/solution/hui-zong-qu-jian-by-leetcode-solution-6zrs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
值得注意的是其中的代码 
```cpp 
ret.push_back(move(temp));
```

#### 参考资料
1. [理解C++右值引用和std::move](https://zhuanlan.zhihu.com/p/87456374)
2. [c++11特性之std-move的使用和原理](https://wendeng.github.io/2019/05/14/c++%E5%9F%BA%E7%A1%80/c++11std-move%E4%BD%BF%E7%94%A8%E4%B8%8E%E5%8E%9F%E7%90%86/)
