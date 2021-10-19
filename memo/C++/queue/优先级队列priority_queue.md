<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 11:25:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 11:54:14
-->
# 声明
```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

# 参数
| 名称      | 用途                                                                        |
| --------- | --------------------------------------------------------------------------- |
| T         | 元素类型                                                                    |
| Container | 存储元素的容器类型，标准类型为```std::vector```和```std::deque```           |
| Compare   | 比较方法，默认情况下返回 **严格弱序** 的结果（即两个元素值相同，返回`false` |

默认情况下是大顶堆。

```cpp
//升序队列，小顶堆
priority_queue <int,vector<int>,greater<int> > q;
//降序排列，大顶堆
priority_queue <int,vector<int>,less<int> > q;
```

# 方法
## 获取元素
### **top()**
返回优先队列的队首元素。

## 修改队列
### **pop()**
弹出优先队列的队首元素。

返回值为空（void）。
### **push()**
```void push( value_type&& value );```

将给定的元素入队并按照优先级排好序。

### **emplace()**
在队列里构建新的给定的元素并按照优先级排好序。

### **swap()**
交换两个优先队列的值。

使用示例（摘自官网）：
```cpp
#include <algorithm>
#include <iostream>
#include <queue>
 
int main()
{
    std::priority_queue<int> alice;
    std::priority_queue<int> bob;
 
    auto print = [](const auto & title, const auto &cont) { 
        std::cout << title << " size=" << cont.size();
        std::cout << " top=" << cont.top() << '\n';
    };
 
    for (int i = 1; i < 4; ++i)
        alice.push(i);
    for (int i = 7; i < 11; ++i)
        bob.push(i);
 
    // Print state before swap
    print("alice:", alice);
    print("bob  :", bob);
 
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
 
    // Print state after swap
    print("alice:", alice);
    print("bob  :", bob);
}
```
运行结果为：
```cpp
alice: size=3 top=3
bob  : size=4 top=10
-- SWAP
alice: size=4 top=10
bob  : size=3 top=3
```
## 容量
### **empty()**
判断优先队列是否为空。如果为空，返回`true`；否则返回`false`。

### **size()**
返回优先队列的元素数量。

# 其他
1. 如果用 `pair` 作比较的话，默认情况下先比较第一个元素，第一个元素相等再比较第二个。

2. [用自定义类型做优先队列元素的例子](https://www.cnblogs.com/huashanqingzhu/p/11040390.html)
    ```cpp
    #include <iostream>
    #include <queue>
    using namespace std;

    //方法1
    struct tmp1 //运算符重载<
    {
        int x;
        tmp1(int a) {x = a;}
        bool operator<(const tmp1& a) const
        {
            return x < a.x; //大顶堆
        }
    };

    //方法2
    struct tmp2 //重写仿函数
    {
        bool operator() (tmp1 a, tmp1 b)
        {
            return a.x < b.x; //大顶堆
        }
    };

    int main()
    {
        tmp1 a(1);
        tmp1 b(2);
        tmp1 c(3);
        priority_queue<tmp1> d;
        d.push(b);
        d.push(c);
        d.push(a);
        while (!d.empty())
        {
            cout << d.top().x << '\n';
            d.pop();
        }
        cout << endl;

        priority_queue<tmp1, vector<tmp1>, tmp2> f;
        f.push(b);
        f.push(c);
        f.push(a);
        while (!f.empty())
        {
            cout << f.top().x << '\n';
            f.pop();
        }
    }
    ```
    输出结果为：
    ```cpp
    3
    2
    1
    
    3
    2
    1
    ```