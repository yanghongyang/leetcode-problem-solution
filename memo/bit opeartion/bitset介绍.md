<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-15 08:18:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-15 08:29:50
-->
#### 缘起
做了以下 `leetcode` 的第 `89` 题（[格雷编码](https://leetcode-cn.com/problems/gray-code/)），发现虽然能大致知道是使用 **回溯** 算法，但很难搞定比特位的操作。

上网查到了可以使用 `bitset` 来解题。记录如下。

#### 声明
以下内容摘自博客 **自为风月马前卒** 的 [bitset用法小结](https://www.cnblogs.com/zwfymqz/archive/2018/04/02/8696631.html)。

#### bitset
`bitset` 大概就是类似于 `bool` 数组一样的东西

但是它的每个位置只占 `1bit`（特别特别小）

`bitset` 的原理大概是将很多数压成一个，从而节省空间和时间（暴力出奇迹）

一般来说 `bitset` 会让你的算法复杂度 /32（具体是什么要看计算机）

#### 定义与初始化
使用 `bitset` 类型需 `#include<bitset>`

`bitset` 类型在定义时就需要指定所占的空间，例如

```cpp
bitset<233>bit;
```

`bitset` 类型可以用 `string` 和整数初始化（整数转化成对应的二进制）。

```cpp []
#include<iostream>
#include<bitset>
#include<cstring>
using namespace std;
int main()
{
    bitset<23>bit (string("11101001"));
    cout<<bit<<endl;
    bit=233;
    cout<<bit<<endl;
    return 0;
}
```

输出结果为

```cpp []
00000000000000011101001
00000000000000011101001
```

#### 基本运算
`bitset` 支持所有位运算。

```cpp []
bitset<23>bita(string("11101001"));
bitset<23>bitb(string("11101000"));
cout<<(bita^bitb)<<endl;
//输出00000000000000000000001 

bitset<23>bita(string("11101001"));
bitset<23>bitb(string("11101000"));
cout<<(bita|bitb)<<endl;
//输出00000000000000011101001

bitset<23>bita(string("11101001"));
bitset<23>bitb(string("11101000"));
cout<<(bita&bitb)<<endl;
//输出00000000000000011101000

bitset<23>bit(string("11101001"));
cout<<(bit<<5)<<endl;
//输出00000000001110100100000

bitset<23>bit(string("11101001"));
cout<<(bit>>5)<<endl;
//输出00000000000000000000111
```

#### 常用函数
对于一个叫做 `bit` 的 `bitset`：

|函数|解释|
|---|---|
|bit.size()      |返回大小（位数）|
|bit.count()     |返回1的个数|
|bit.any()       |返回是否有1|
|bit.none()      |返回是否没有1|
|bit.set()       |全都变成1|
|bit.set(p)      |将第p + 1位变成1（bitset是从第0位开始的！） |
|bit.set(p, x)   |将第p + 1位变成x|
|bit.reset()     |全都变成0|
|bit.reset(p)    |将第p + 1位变成0|
|bit.flip()      |全都取反|
|bit.flip(p)     |将第p + 1位取反|
|bit.to_ulong()  |返回它转换为unsigned long的结果，如果超出范围则报错|
|bit.to_ullong() |返回它转换为unsigned long long的结果，如果超出范围则报错|
|bit.to_string() |返回它转换为string的结果|