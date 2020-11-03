<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-03 11:22:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-03 11:32:45
-->
### 简介
vector中也有erase方法，用来删除vector的单个元素（凭借元素位置）或者一整个范围的元素（给定起始位置和终止位置）。

### 函数声明
```cpp
iterator erase (const_iterator position);   //用于删除特定位置的元素
iterator erase (const_iterator first, const_iterator last); //用于删除[first, last)的所有元素
```

### 参数
1. position


    指向想要在vector中删除的元素的位置。

2. first, last
   
    两个迭代器iterator，分别指向待删除元素区间的起始位置和终止位置。注意这里是左闭右开区间，即[first, last)。

### 返回值
指向最后一个被删除元素后的第一个位置的迭代器iterator。

### 示例代码
```cpp
// erasing from vector
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
```
输出结果为：
```cpp
myvector contains: 4 5 7 8 9 10
```

### 时间复杂度
线性，即正比于（删除元素+该元素后所有元素）。