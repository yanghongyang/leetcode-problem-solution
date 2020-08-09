<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-09 11:35:46
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-09 11:53:25
-->
# [题目描述](https://leetcode-cn.com/problems/combination-sum-ii/)

给定一个数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用一次。
```
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
```
```
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```
```
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
```
# 考点（解题方向）
- 回溯！！！
- 动态规划......

# 题目分析
这道题和[组合总和](https://leetcode-cn.com/problems/combination-sum/)是一个系列的。不过加了一些限制条件。

受到[组合总和](https://leetcode-cn.com/problems/combination-sum/)的解题思路影响，这道题除了回溯法之外，也可以被看作`0-1背包`来解答。~~然鹅懒惰的我翻遍了C++解法也没找到传说中的CPP动态规划解法...于是自己写了一个贼不优雅的解答。~~

**回溯** 的方法还是比较简单的，把dfs函数中的条件给改一下就可以了，之前可以无限次使用同一个位置的数字，现在对这个条件加以限定，判断完本位置的数字之后必须判断接下来位置的数字。

**动态规划** 方法的一个难点是处理重复数字。~~这一点写了好久~~。实现过程中使用了高级数据结构`set`和`unordered_map`，这两种数据结构虽然在[组合总和](https://leetcode-cn.com/problems/combination-sum/)中也使用了，但写在这里以强调其 **数据结构** 重要性。*私以为本篇题解的意义在于其提供了CPP版动态规划解法，代码太臭什么的求轻喷*。

# ~~闲扯内容~~
对于这道题，实际上很像大一大二时候做的算法题（考0-1背包的时候？），题目描述类似于`小明有很多国家的很多种硬币，但是每种硬币只有1个，现在小明想买一个价值为y的冰淇淋，有多少种买法`之类的......

可能例子可能不够准确，但是意思差不多对，如果非要说不对的话，就是很多国家很多种硬币这个事儿，这里统一成了硬币之间汇率是1:1（根本没啥实际意义汇率都1:1了），稍微复杂一点可以说不同货币之间汇率不同之类的balabalabala......

# 代码（回溯）
```
class Solution {
public:
    //回溯算法，从组合总和I的代码直接改改就行了...
    void dfs(int pos, int target, int n, vector<int>& tmp, vector<vector<int>>& res, vector<int>& candidates)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }
        int i = pos;
        while(i < n && target - candidates[i] >= 0)
        {
            if(i == pos || candidates[i] != candidates[i - 1])
            {
                tmp.push_back(candidates[i]);

                dfs(i + 1, target - candidates[i], n, tmp, res, candidates);

                tmp.pop_back();
            }
            i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(0, target, candidates.size(), tmp, res, candidates);
        return res;
    }
};
```
# 代码（动态规划）
```
class Solution {
public:
    //动态规划，准确地说是0-1背包
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, set<vector<int>>> res;   //建立整数到集合的映射，集合中包含和为该整数的所有组合）
        for(int i = 1; i <= target; i++)    //对于i来讲，从1一直循环计算到target
        {
            for(int j = 0; j < candidates.size(); j++)   //对于candidates中的每个数
            {
                if(candidates[j] == i) //最理想的情况当然是i存在于candidates中啦，这样直接放在对应的集合里就行啦
                {
                    if(res[i].count(vector<int>{j}) == 0)
                        res[i].insert(vector<int>{j}); 
                }    
                else if(candidates[j] < i) //但是很多情况下it的值是比i小的，因此就需要看是否能在candidates中找到值为i-it的数字，将其对应的集合加到答案里
                {
                    for(auto tmp : res[i - candidates[j]])
                    {
                        vector<int> t(tmp);
                        if(find(t.begin(), t.end(), j) == t.end())
                        {
                            t.push_back(j);
                            sort(t.begin(), t.end());
                            if(res[i].count(t) == 0)
                                res[i].insert(t);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : res[target])
        {
            vector<int> tmp;
            for(auto itt : it)
            {
                tmp.push_back(candidates[itt]);
            }
            sort(tmp.begin(), tmp.end());
            if(find(ans.begin(), ans.end(), tmp)== ans.end())
                ans.push_back(tmp);
        }
        return ans;
    }
};
```