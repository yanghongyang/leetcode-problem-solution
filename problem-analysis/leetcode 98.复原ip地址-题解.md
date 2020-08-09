# [题目描述](https://leetcode-cn.com/problems/restore-ip-addresses/)

给定一个只包含数字的字符串，复原它并返回所有可能的 `IP` 地址格式。

有效的 `IP` 地址正好由四个整数（每个整数位于 `0` 到 `255` 之间组成），整数之间用 `'.'` 分隔。

 
```
示例:
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
```

# 考点（解题方向）
- 回溯
- 暴力模拟

# 题目分析
这道题和[电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)、[括号生成](https://leetcode-cn.com/problems/generate-parentheses/) 有异曲同工之妙（可以同时食用，效果更佳）。

**小wai小men总xie结dao：**

*如果遇到要穷举所有可能啊，所有组合之类的话，最好用的方法就是回溯法（dfs）*

当然如果暴力的话也不是不可取......这种还是分情况的。针对于本题来讲，因为可以针对字符串的长度和每一部分进行**大幅度的剪枝**，长度也只能在0到12这个范围内才合理。因此使用暴力法还是相对可行的。

如果使用 **回溯法** 的话，那么按照套路来讲，会有一个dfs函数。在dfs函数中，首先判断特殊情况，接着对普通情况进行处理。

在本题中，特殊情况有：
1. 已经搜索到最后一部分。 
2. 搜索长度过大或过小（众所周知，长度应该在0到3位之间）

根据特殊情况判断之后，对普通情况进行处理。本题中的处理应该是判断数字是否在0~255之间。如果合法，继续dfs。

**暴力法** 的话......感觉没啥好说的，三重for循环判断四个子字符串的十进制数值是否合法即可。

# 代码（回溯）
```
class Solution {
public:
    //这道题一看就是...回溯法
    //回溯法万岁！
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
    void dfs(string s, int start, int step, string ip, vector<string>& result)
    {
        if(start == s.size() && step == 4)
        {
            ip.erase(ip.end() - 1); //移掉最后一个'.'
            result.push_back(ip);
            return ;
        }
        if(s.size() - start > (4 - step) * 3)
            return; //这意味着剩下的数字太多了
        if(s.size() - start < (4 - step))
            return; //这意味着剩下的数字太少了
        int num = 0;
        for(int i = start; i < start + 3; i++)  //因为分隔的数字大小在0~255之间，所以顶多3位
        {
            num = num * 10 + (s[i] - '0');
            //如果num在0~255之间的话
            if(num <= 255)
            {
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', result);
            }
            if(num == 0)
                break;
        }
    }
};
```

# 代码（暴力）
```
class Solution {
public:
    bool valid(string s)
    {
        //0~255意味着不超过3位
        if(s.size() <= 0 || s.size() > 3)
            return false;
        //除此之外s不能以0为开头
        if(s[0] == '0' && s.size() > 1)
            return false;
        //计算数的大小
        int result = 0;
        for(int i = 0; i < s.size(); i++)
        {
            result = result * 10 + s[i] - '0';
        }
        return (result >= 0 && result <= 255);
    }
    vector<string> restoreIpAddresses(string s) 
    {
        int n = s.size(); 
        vector<string> res;
        if(n > 12 || n < 4) //肯定不可能分成4个合理的部分
            return {};
        for(int i = 1; i < n; i++)
        {
            string a = s.substr(0, i);  //第一部分
            if(valid(a))
            {
                for(int j = i + 1; j < n; j++)
                {
                    string b = s.substr(i, j - i);
                    if(valid(b))
                    {
                        for(int k = j + 1; k < n; k++)
                        {
                            string c = s.substr(j, k - j);
                            string d = s.substr(k, n - k);
                            if(valid(c) && valid(d))
                            {
                                res.push_back(a + '.' + b + '.' + c + '.' + d);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
```