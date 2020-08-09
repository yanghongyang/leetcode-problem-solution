<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-09 12:20:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-09 12:21:53
-->
# 题目描述

给定一个 **没有重复** 数字的序列，返回其所有可能的全排列。

```
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

# 考点
- 回溯

# 题目分析
回溯法的经典应用......没啥好说的

# 代码（回溯）
```
class Solution {
public:
    void dfs(int start, vector<int>& tmp, vector<vector<int>>& res, vector<int>& nums, int n)
    {
        if(start == n)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = 0; i <= tmp.size(); i++)
        {
            tmp.insert(tmp.begin() + i, nums[start]);
            dfs(start + 1, tmp, res, nums, n);
            tmp.erase(tmp.begin() + i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(0, tmp, res, nums, nums.size());
        return res;
    }
};
```