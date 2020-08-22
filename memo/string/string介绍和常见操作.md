<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-21 08:20:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-21 08:46:25
-->
# 定义
| Type        | Definition              |
| ----------- | ----------------------- |
| std::string | std::basic_string<char> |

# 常见方法
## 获取元素
### at()
    - 参数：元素的位置
    - 返回该元素的引用（这意味着可以修改该位置的值）
    - 例子：
        ```
        string s = "abc"; 
        s.at(2) = 'x';   
        std::cout << s << endl; //结果是"abx"
        ```
### front()
    - 无参数
    - 返回string对象的首个字符（可以改变它的值）
    - 例子：
        ```
        string s1("test");
        s1.front() = 'T';
        cout << s1 << endl; //输出"Test"
        ```
### back()
    - 无参数
    - 返回string对象的最后一个字符（可以改变它的值）
    - 例子：
        ```
        string s1("test");
        s1.back() = "T";
        cout << s1 << endl; //输出"tesT"
        ```
## 迭代器
### begin()

### end()

### rbegin()

### rend()

## 容量
### empty()

### size()/length()

### max_size()

### reserve()

### capacity()

## 操作
### clear()

### insert()

### erase()

### push_back()

### pop_back()

### append()

### compare()

### starts_with()

### ends_with()

### replace()

### substr()

### copy()

### resize()

### swap()

## 搜索
### find()

### rfind()

### find_first_of()

### find_first_not_of()

### find_last_of()

### find_last_not_of()