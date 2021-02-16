/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        stack<int> oper;
        int ans = 0;
        int num = 0;      //用来处理数字
        s.push_back('#'); //为了保证最后一个符号能够被代入计算
        char presym = '+';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || s[i] == ')' || s[i] == '(')
                continue;                        //吃掉空格
            else if (s[i] >= '0' && s[i] <= '9') //处理数字
            {
                num *= 10;
                num += (s[i] - '0');
            }
            else                   //当前的 s[i] 是加减乘除四种符号之一
            {                      //首先，本题中给出的公式是有效的，也就是说，数字一定先于符号，并通过之前的 if 语句进行了处理
                if (presym == '+') //如果当前符号之前的符号是加号，可以直接压入栈中
                    oper.push(num);
                else if (presym == '-') //如果当前符号之前的符号是减号，要想得到正确结果，需要将其相反数压栈
                    oper.push(-num);
                //接下来清零重新计算运算数，并且更新之前符号
                num = 0;
                presym = s[i];
            }
        }
        while (!oper.empty())
        {
            ans += oper.top();
            oper.pop();
        }
        return ans;
    }
};
// @lc code=end
