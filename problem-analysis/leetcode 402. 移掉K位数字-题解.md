<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-21 08:10:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-21 08:15:49
-->
# [题目描述](https://leetcode-cn.com/problems/remove-k-digits)
给定一个以字符串表示的非负整数 `num`，移除这个数中的 `k` 位数字，使得剩下的数字最小。

```
注意:
num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
```
```
示例 1 :
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
```
```
示例 2 :
输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
```
```
示例 3 :
输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。
```
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点
- 单调栈

# 题目分析
本题实际上是在区间内去掉最大的 `k` 个数字。因此从思路上来讲应该维护一个单调栈。规则为：如果当前元素小于栈顶元素，则弹出栈顶元素。（弹出`k`次）

# 代码（单调栈）
```cpp
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res;
        int n = num.size();
        int m = n - k;
        for (auto &c : num)
        {
            while (k && res.size() && res.back() > c)
            {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        res.resize(m);
        //去除前导0
        while (!res.empty() && res[0] == '0')
        {
            res.erase(res.begin());
        }
        return res.empty() ? "0" : res;
    }
};
```