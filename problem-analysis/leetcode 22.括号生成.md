<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-08-08 12:23:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-08 12:37:38
-->

# [题目描述](https://leetcode-cn.com/problems/generate-parentheses/)

数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 `有效的` 括号组合。

```
示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
```

# 考点（解题方向）

- 回溯
- 动态规划

# 代码（回溯）

这道题和全排列还有[电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)很类似，主要考察的点都是 **回溯** 思想。

代码如下：

```
class Solution {
public:
    vector<string> letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string tmp = "";
        dfs(digits, 0, tmp, res, letter);
        return res;
    }
    void dfs(string digits, int pos, string& path, vector<string>& res, vector<string>& letter)
    {
        if(pos == digits.size())
        {
            res.push_back(path);
            return ;
        }
        for(auto c : letter[digits[pos] - '0'])
        {
            path.push_back(c);
            dfs(digits, pos + 1, path, res, letter);
            path.pop_back();
        }
    }
};
```

# 代码（动态规划/迭代）

通过进一步了解，发现这道题还有 **动态规划** 的解法。

详情参考 [【最简单易懂的】动态规划](https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/)。

在 CPP 解法的代码中进行了部分注释，也可参考。

```
class Solution {
public:
    //很显然，这道题如果用bfs的话，实在是麻烦......
    //在网上还看到动态规划(也叫做迭代）的做法，抄了下来留作学习
    //总体思路是，对于一对括号来讲，可以生成(+l+)+r的形式。其中如果l为i对括号组成的括号对，则r为（n-1-i）对括号组成的括号对
    vector<string> generateParenthesis(int n)
    {
        if(!n)
            return {""};
        vector<string> res;
        for(int i = 0; i < n; i++)
        {
            for(string l : generateParenthesis(i))
            {
                for(string r : generateParenthesis(n - 1 - i))
                {
                    res.push_back('(' + l + ')' + r);
                }
            }
        }
        return res;
    }
};
```
