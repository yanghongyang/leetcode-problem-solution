# [题目描述]()

给定一个整数数组 `asteroids`，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

```
示例 1:
输入:
asteroids = [5, 10, -5]
输出: [5, 10]
解释:
10 和 -5 碰撞后只剩下 10。 5 和 10 永远不会发生碰撞。
```

```
示例 2:
输入:
asteroids = [8, -8]
输出: []
解释:
8 和 -8 碰撞后，两者都发生爆炸。
```

```
示例 3:
输入:
asteroids = [10, 2, -5]
输出: [10]
解释:
2 和 -5 发生碰撞后剩下 -5。10 和 -5 发生碰撞后剩下 10。
```

```
示例 4:
输入:
asteroids = [-2, -1, 1, 2]
输出: [-2, -1, 1, 2]
解释:
-2 和 -1 向左移动，而 1 和 2 向右移动。
由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。
```

```
说明:
数组 asteroids 的长度不超过 10000。
每一颗行星的大小都是非零整数，范围是 [-1000, 1000] 。
```

```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/asteroid-collision
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

# 考点

- 栈
- 模拟

# 题目分析

讲道理，这题的难度标成 **中等** 有一点名不副实......QAQ

看题目，分析以下段落：

```
两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
```

看到 **爆炸** 想到啥？行星没有了。行星没有了意味着啥？意味着 `asteriod` 数组中对应的元素没有了。怎么没有了？因为该元素小于/等于它之后的元素的绝对值。

那么很容易想到一个数据结构 **栈** 。（因为涉及到当前最后一个元素和之后的元素，还涉及到可能会发生的频繁删除末尾元素）

因此按照碰撞规则可以很容易写出代码。

# 代码

- 用 vector 模拟栈

```cpp
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        for (int a : asteroids)
        {
            bool destroyed = false;
            while (res.size() && res.back() > 0 && a < 0 && !destroyed)
            {
                if (res.back() >= -a)
                    destroyed = true;
                if (res.back() <= -a)
                    res.pop_back();
            }
            if (!destroyed)
                res.push_back(a);
        }
        return res;
    }
};
```

当然这么优雅的代码我是写不出来的......

我的想法就是老老实实用栈......

附上代码：

- 使用 stack 数据结构

```cpp
vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> res;
    stack<int> s;
    s.push(INT_MIN); //这里压入INT_MIN有个好处：当asteroids的首元素为负值时不用担心碰撞，直接压栈即可；当首元素为正值时，也不用担心碰撞，直接压栈就行。
    for (int a : asteroids)
    {
        if (a < 0)
        {
            while (s.top() > 0 && s.top() < -a)
            {
                s.pop(); //如果栈顶大于零并且符合碰撞规则，出栈。
            }
            if (s.top() < 0)
            {
                s.push(a);
            }
            else if (s.top() == -a)
            {
                s.pop(); //如果栈顶元素和当前元素相等，还是碰撞了，出栈。
            }
        }
        else
        {
            s.push(a);
        }
    }
    while (s.size() != 1)
    {
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
```
