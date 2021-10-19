<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-11 17:22:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-11 17:42:24
-->

#### 声明
参考自：
1. [c++判断vector中是否存在特定元素的方法](https://blog.csdn.net/guotianqing/article/details/105832070)
2. [C++ STL算法系列count函数](https://blog.csdn.net/lyj2014211626/article/details/69615514)


#### 简介
`vector` 中未提供查找元素是否存在或确定元素个数的方法。

但是，在 `algorithm` 模块中提供了查找的多种方式。

对于任意的vector，查找某个元素需要消耗线性时间。除非该vector是有序的。

#### std::count
`count` 函数的功能是：统计容器中等于 `value` 元素的个数。

对于只需要知道包含特定元素的数量的应用来说，这是 **最简单** 的方式。如果 `count` 返回 `0` ，则表示不存在该元素。

函数声明：
```cpp []
count(first,last,value); //first是容器的首迭代器，last是容器的末迭代器，value是询问的元素。
```

##### 延伸：std::count_if
`count_if` 用来统计满足特定条件的元素的个数。

函数声明：
```cpp []
count_if(first,last,value,comp); //first为首迭代器，last为末迭代器，value为要查询的元素，comp为比较函数。
```

其中 `comp` 函数是核心。

#### std::find
`find` 会在查找到指定值的时候立刻返回。因此它一般比 `count` 更快。

案例：
```cpp []
if (std::find(v.begin(), v.end(), key) != v.end())
```

#### std::find_if
`find_if` 感觉和 `count_if` 挺像的？ 它需要一个判别式，如果查找的值满足特定的条件时，就可以用这种方式。

如果有多个值符合条件，则返回查找到符合条件的第一个值的迭代器。

案例：
```cpp []
//查找小于3且大于1的值
if (std::find_if(v.begin(), v.end(), [] (int i) { return i < 3 && i > 1 } ) != v.end())
```

#### std::any_of
`any_of` 和 `find_if` 类似，但是它返回 `bool` 值。

如果判断式返回 `true`，则它也返回 `true`，否则返回 `false`。

案例：
``` cpp[]
if (std::any_of(v.begin(), v.end(), [] (int i) { return i < 3 && i > 1 } ))
```

#### std::binary_search
二分查找......
先对 `vector` 排序，然后再使用这个方法。

案例：
```cpp[]
sort(v.begin(), v.end());
if (std::binary_search(v.begin(), v.end(), key))
```

#### 方法对比
|方法|适用场景|
|----|----|
|binary_search|已排序vector|
|find|仅判断是否存在某元素|
|count|需要某元素总个数|
|any_of|复杂条件的查找，仅知道是否存在|
|find_if|复杂条件的查找，返回第一个元素的迭代器|