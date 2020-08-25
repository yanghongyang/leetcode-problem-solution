/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-25 16:51:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-25 17:11:04
 */
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
// @lc code=start
class Solution
{
public:
    bool isoper(string s)
    {
        if (s != "+" && s != "-" && s != "*" && s != "/")
            return false;
        return true;
    }
    int exchange(string s)
    {
        int ans = 0;
        int flag = 1; //表示默认情况下是正数
        if (s[0] == '-')
            flag = -1;
        else
            ans += s[0] - '0';
        for (int i = 1; i < s.size(); i++)
        {
            ans = ans * 10 + s[i] - '0';
        }
        return ans * flag;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> ans;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (!isoper(tokens[i]))
            {
                ans.push(exchange(tokens[i]));
            }
            else
            {
                int a = ans.top();
                ans.pop();
                int b = ans.top();
                ans.pop();
                if (tokens[i] == "+")
                    ans.push(a + b);
                else if (tokens[i] == "-")
                    ans.push(b - a);
                else if (tokens[i] == "*")
                    ans.push(a * b);
                else if (tokens[i] == "/")
                    ans.push(b / a);
            }
        }
        return ans.top();
    }
};
// @lc code=end
