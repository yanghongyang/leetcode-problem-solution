<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-24 21:39:27
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-24 22:09:50
-->
## 简介
`upper_bound()` 和 `lower_bound()` 是 `C++` 的 `algorithm` 库中的函数。分别用来在排序数组中查找第一个大于 `num` 的位置和第一个大于等于 `num` 的位置。

## 用法
### upper_bound()
#### 声明及参数
##### 声明
```cpp
template <class ForwardIterator, class T, class Compare>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```
##### 参数
|名称|意义|
|---|---|
|first, last|前向迭代器，范围为[first, last)（通常为nums.begin()和nums.end()）|
|val|在规定范围内想要查找其下界的元素值|
|comp|可选，二分比较函数，自己写的话需要有两个参数，分别为vector的两个迭代器，返回bool值。|

### lower_bound()
#### 声明及参数
##### 声明
```cpp
template <class ForwardIterator, class T, class Compare>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```
一般而言，更常用的是这个形式：
```cpp
upper_bound(nums.begin(), nums.end(), val); //其中，nums是一个vector，val是想要查找到其上界的值
```

##### 参数
和 `upper_bound()` 的参数相同。

## C++ Reference上给出的例子
代码
```cpp
// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
```
输出
```sh
lower_bound at position 3
upper_bound at position 6
```

## 复杂度
平均而言，二者的时间复杂度都是 `first` 和 `last` 之间的距离取对数，即 $log_2{N} + 1$，其中 `N` 是 `first`和 `last` 之间的距离。

## 可能的实现方式
**注意**

以下代码抄自：[lower_bound和upper_bound的实现和基本用法](https://www.cnblogs.com/bianjunting/p/10581368.html)

### upper_bound()

```cpp
int upper_bound(vector<int> &a, int val) {
    int first = 0, last = a.size() - 1, mid;
    while(first <= last) {
        mid = last - (last - first) / 2;
        if(a[mid] <= val) first = mid + 1;
        else last = mid - 1;
    }
    return first;
}
```

### lower_bound()
```cpp
int lower_bound(vector<int> &a, int val) {
    int first = 0, last = a.size() - 1, mid;
    while(first <= last) {
        mid = last - (last - first) / 2;
        if(a[mid] >= val) last = mid - 1;
        else first = mid + 1;
    }
    return first;
}
```

## 参考文章&网址
1. [关于lower_bound( )和upper_bound( )的常见用法](https://blog.csdn.net/qq_40160605/article/details/80150252)
2. [lower_bound和upper_bound的实现和基本用法](https://www.cnblogs.com/bianjunting/p/10581368.html)
3. [lower_bound() 函数使用详解](https://www.cnblogs.com/woxiaosade/p/11402748.html)
4. [C++ Reference](http://www.cplusplus.com/reference/algorithm/lower_bound/)