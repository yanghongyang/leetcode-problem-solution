/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
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
    //暴力模拟，由于一遍循环，效果出奇的好
    /* int myAtoi(string str) {
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
    } */
    //有限状态机
    int myAtoi(string str)
    {
        Automata dfa;
        for(char c : str)
            dfa.get(c);
        return dfa.sign * dfa.ans;
    }
};
// @lc code=end

