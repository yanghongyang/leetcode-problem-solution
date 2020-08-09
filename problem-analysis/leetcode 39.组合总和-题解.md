# 题目描述
给定一个无重复元素的数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的数字可以无限制重复被选取。

```
说明：
所有数字（包括 `target`）都是正整数。
解集不能包含重复的组合。 
```
```
示例 1：
输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
```
```
示例 2：
输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```
```
提示：
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
```

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点（解题方向）
- 回溯！回溯！回溯！！！
- 动态规划？？？？？？？（不知道到底算不算动态规划但是他们都这么说/摊手）

# 题目分析
这题emmmmm......

使用回溯法肯定是第一想法，因为涉及到问**多少种组合**。

其实这道题和大一大二的某个算法题很像（小明有几种硬币，硬币个数无穷多，一个雪糕y元，问小明有多少种给零钱来买雪糕的组合balabalabala类似这样的）。

**回溯** 的思路较为简单，因为dfs的实现有套路可循：剪枝+处理。

首先判断当前组合是否达到了`target`，如果达到的话就是一种`result`。

剪枝的判断基于是否将整个数组遍历完以及当前组合的数字和。

这种基本回溯类型的题的一大优点是，基本不咋用动脑子......只要能把dfs写出来，题就基本做完了......没什么好说的。

**动态规划** 方法是我没想到的，但是一般来讲可以用dfs方法解决的问题，也可以用迭代的方式解决。

所以搜题解的时候搜到了一篇。在这里：[超强gif助你理解使用“动态规划”求解本题](https://leetcode-cn.com/problems/combination-sum/solution/chao-qiang-gifzhu-ni-shi-yong-dong-tai-gui-hua-qiu/)。

动画gif画的有点厉害（尤其是`target`为`5`的情况属实鬼畜），让我不禁点了个赞（棒棒哒！）

对于这种方法的大致思路和解析写在了代码里，帮助理解（如果能看懂的话）。

如果被上面提供的链接给弄得有一点晕，可以将本题理解为一个**背包问题**。状态转移方程为：`dp[i]+=dp[i-x]`，`dp[i]`的意思为目标为`i`的情况下所有可能的组合。纯代码实现更推荐这篇：[C++ 动态规划-转化为背包问题](https://leetcode-cn.com/problems/combination-sum/solution/c-dong-tai-gui-hua-zhuan-hua-wei-bei-bao-wen-ti-by/)。

# 代码（回溯）
```
class Solution {
public:
    void dfs(int pos, int target, vector<int>& tmp, vector<vector<int>>& res, vector<int>& candidates)
    {
        if(target == 0)
        {
            res.push_back(tmp);
            return ;
        }
        if(pos == candidates.size() || (target - candidates[pos]) < 0)
            return ;

        tmp.push_back(candidates[pos]);

        dfs(pos, target - candidates[pos], tmp, res, candidates);

        tmp.pop_back();

        dfs(pos + 1, target, tmp, res, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(0, target, tmp, res, candidates);
        return res;
    }
};
```

# 代码（动态规划）
```
class Solution {
public:
    //这道题其实还有迭代解法，对应的是动态规划。
    //万分感谢C++强大的STL
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        unordered_map<int, set<vector<int>>> res;   //建立整数到集合的映射，集合中包含和为该整数的所有组合）
        for(int i = 1; i <= target; i++)    //对于i来讲，从1一直循环计算到target
        {
            for(auto it : candidates)   //对于candidates中的每个数
            {
                if(it == i) //最理想的情况当然是i存在于candidates中啦，这样直接放在对应的集合里就行啦
                    res[i].insert(vector<int>{it});
                else if(it < i) //但是很多情况下it的值是比i小的，因此就需要看是否能在candidates中找到值为i-it的数字，将其对应的集合加到答案里
                {
                    for(auto tmp : res[i - it])
                    {
                        tmp.push_back(it);  //这里选择加it是因为tmp每一次都更新，但是it是固定的。方便。
                        sort(tmp.begin(), tmp.end());   //啊这...这里必须进行排序，防止出现[2,2,3]和[2,3,2]的情况（实际上两者的和都是7）
                        if(res[i].count(tmp) == 0)  //看有没有重复的
                            res[i].insert(tmp);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it : res[target])
            ans.push_back(it);
        return ans;
    }
};
```