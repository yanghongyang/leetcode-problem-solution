<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-10 12:09:58
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-10 12:29:04
-->
# 函数声明

```
istream& getline ( istream &is , string &str , char delim );
```

**参数解释**
| 参数  | 解释                                                         |
| ----- | ------------------------------------------------------------ |
| is    | 输入流                                                       |
| str   | 将读取到的字符串存储到的地方                                 |
| delim | 分隔符，读入该字符则输入终止。可省略（默认为'\n'，即换行符） |

# 例子
参见[leetcode 71.简化路径](https://leetcode-cn.com/problems/simplify-path/)中对字符串的处理。

代码片段截取和修改如下：
```cpp

stringstream is(path);
string tmp = "";
getline(is, tmp, '/')
```

上述代码中，首先`stringstream`类型的`is`负责读取`path`。在使用`getline()`函数的时候，当`is`读到了`'/'`就终止，并将之前读到的字符串全部存储到`tmp`变量中。

再例如（代码摘自[getline函数](https://www.cnblogs.com/liugl7/p/4807034.html)）：
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    string data;
    getline(cin,data,'$');
    cout<<data;
} 
```
则当输入为`It's a apple$!`的时候，输出为`It's a apple`。


# 用处
在CPP做题过程中的用处为：
1. 和`while`循环结合使用，起到**分隔字符串**的作用。非要问它和`split`的作用有啥不同的话，大概就是split分好的各个字符串不能够实时处理，而`getline()`这个函数可以实时处理这些字符串，也就不用考虑字符串长度的问题，并且节省了一个vector来存储分隔的字符串（只需要一个变量`tmp`即可，参见lc 71题）。