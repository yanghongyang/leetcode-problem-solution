<!--
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-07 21:21:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-07 21:40:39
-->
# [题目描述](https://leetcode-cn.com/problems/string-to-integer-atoi)
请你来实现一个 `atoi` 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。

假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。

该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 `0` 。

**提示：**

本题中的空白字符只包括空格字符 `' '` 。

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 `[−2^31,  2^31 − 1]`。如果数值超过这个范围，请返回  `INT_MAX (2^31 − 1)` 或 `INT_MIN (−2^31)` 。
 
```
示例 1:
输入: "42"
输出: 42
```
```
示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```
```
示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```
```
示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。
```
```
示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。因此返回 INT_MIN (−231) 。
```
# 考点（解题方向）
- 字符串
- 模拟
- 有限状态机

# 题目分析
1. 看到这题第一反应就是模拟......设置一个标志位用来判断是正数还是负数，除此之外，既然要返回一个数字，并且在`INT_MIN`和`INT_MAX`之间，所以需要一个long类型的变量`num`进行模拟（因为如果是`int`类型可能会溢出）。
   
   如果当前的str[i]是在`'0'`到`'9'`之间的话，则按照常规的方法，`num * 10 + str[i] - '0'`来处理。并且每一次处理之后都需要判断`num`和INT_MIN以及INT_MAX的大小，防止溢出。
2. 除了这个方法，也可以使用C++的输入输出控制类，即istringstream。这种方法其实连INT_MIN和INT_MAX都不用判断了，因为istringstream将会读入符合特定类型的值。即，如果定义一个int类型的变量num，则istringstraem一个变量is并初始化后，is>>num的结果一定是int类型的（不会越界）。个人认为这种方法十tou分ji简qu洁qiao，不失为一种好方法。
3. 第三种想法，是有限状态机。相比较前两种方法显得十you分chou华you丽chang。具体的状态转换可以参考[官方题解](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)。
   
   通过学习，总结：有限状态机的套路为：
   - 确定状态
   - 写hash map表达映射关系
   - 写状态转换函数（对于本题来讲就是根据当前状态判断接下来的状态）
   - 写处理函数（对于本题来讲就是读入字符）
   - 处理，结束

# 代码（暴力模拟）
```
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        int i = 0;
        while(str[i] == ' ')
            i++;
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-') ? -1 : 1;
        while('0' <= str[i] && str[i] <= '9' && i < str.size())
        {
            result = result * 10 + (str[i++] - '0');
            if(result * indicator >= INT_MAX)
                return INT_MAX;
            if(result * indicator <= INT_MIN)
                return INT_MIN;
        }
        return result * indicator;
    }
};
```

# 代码（istringstream）
```
class Solution {
public:
    //当然也可以直接调用isstringstream
    int myAtoi(string str)
    {
        istringstream is(str);
        int num = 0;
        is >> num;
        /* if(num > INT_MAX)
            return INT_MAX;
        else if(num < INT_MIN)
            return INT_MIN;
        else  */
            return num;
    }
};
```

# 代码（有限状态机）
啊...这代码真的太长了......
```
class Automata {
public:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "sign", "innum", "end"}},
        {"sign", {"end", "end", "innum", "end"}},
        {"innum", {"end", "end", "innum", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int get_s(char c)
    {
        if(c == ' ')
            return 0;
        if(c == '+' || c == '-')
            return 1;
        if(isdigit(c))
            return 2;
        return 3;
    }

    long long ans = 0;
    int sign = 1;
    void get(char c)
    {
        state = table[state][get_s(c)]; //根据当前状态选择应该处理的情况
        if(state == "innum")    //如果到了数字处理状态
        {
            ans = ans * 10 + c - '0';
            //接着判断符号位和极值
            if(sign == 1)
            {
                ans = min(ans, (long long)INT_MAX);    //不能超过INT_MAX
            }
            else 
            {
                ans = min(ans, (-1) * (long long)INT_MIN);    //负数的话不能超过INT_MIN
            }
        }
        else if(state == "sign")
        {
            if(c == '-')
                sign = -1;
        }
    }
};
class Solution {
public:
    //有限状态机
    int myAtoi(string str)
    {
        Automata dfa;
        for(char c : str)
            dfa.get(c);
        return dfa.sign * dfa.ans;
    }
};
```
