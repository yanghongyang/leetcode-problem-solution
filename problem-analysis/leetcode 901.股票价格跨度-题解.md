<!--
 * @Description:
 * @Author: Hongyang_Yang
 * @Date: 2020-09-14 21:27:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-14 21:38:02
-->

# [题目描述](https://leetcode-cn.com/problems/online-stock-span/)

编写一个 `StockSpanner` 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。

今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

例如，如果未来 7 天股票的价格是 `[100, 80, 60, 70, 60, 75, 85]`，那么股票跨度将是 `[1, 1, 1, 2, 1, 4, 6]`。

```
示例：
输入：["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
输出：[null,1,1,1,2,1,4,6]
解释：
首先，初始化 S = StockSpanner()，然后：
S.next(100) 被调用并返回 1，
S.next(80) 被调用并返回 1，
S.next(60) 被调用并返回 1，
S.next(70) 被调用并返回 2，
S.next(60) 被调用并返回 1，
S.next(75) 被调用并返回 4，
S.next(85) 被调用并返回 6。
注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格(包括今天的价格 75) 小于或等于今天的价格。
```

提示：
调用  StockSpanner.next(int price)  时，将有  1 <= price <= 10^5。
每个测试用例最多可以调用   10000 次 StockSpanner.next。
在所有测试用例中，最多调用  150000  次  StockSpanner.next。
此问题的总时间限制减少了 50%。

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-stock-span
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点

- 单调栈
- 动态规划

（私以为对于单调栈想不通的同学 ~~比如我~~ ，可以借助动态规划的思想完成本题）

# 题目分析

来个脑筋急转弯哈。

如果已知当前 `price` 对应的 `day` 了，如果之后一天的 `price1` 比 `price` 大，那么 `price1` 对应的 `day1` 就相当于 `day+1` 。

而如果 `price1` 比 `price` 小，那么 `day1` 就是 `1` 了。其后一个的 `price2` 也都只能再从 `price1` 比较了。

依次循环。

因此实现过程中使用的数据结构是一个栈（准确地说是单调栈），而栈中的元素应该是一个 **二元组** ，为 **价格** 和 **天数** 的组。也就是 `stack<pair<int, int>>`。

由于本题的查询是顺序查询，随着时间的推移，答案可能会不断变化，因此维护一个栈结构即可。

# 代码

```cpp
class StockSpanner
{
public:
    stack<pair<int, int>> st; //[price, days]
    StockSpanner()
    {
    }

    int next(int price)
    {
        int days = 1;
        while (st.size() && price >= st.top().first)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        return days;
    }
};
```
