/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    //回溯dfs
/*     vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        dfs(n, 0, 0, tmp, res);
        return res;
    }
    void dfs(int n, int l, int r, string tmp, vector<string>& res) //l和r表示当前括号的对数
    {
        if(l == n && r == n)
        {
            res.push_back(tmp);
            return ;
        }
        else 
        {
            if(l < n)   //如果还没到n对括号
            {
                dfs(n, l + 1, r, tmp + '(', res);
            }
            if(r < l)   //如果此时左括号和右括号对不上，左括号多，则需要补充右括号
            {
                dfs(n, l, r + 1, tmp + ')', res);
            }
        }
    } */
    //很显然，这道题如果用bfs的话，实在是麻烦......
    //在网上还看到动态规划(也叫做迭代）的做法，抄了下来留作学习
    //总体思路是，对于一对括号来讲，可以生成(+l+)+r的形式。其中如果l为i对括号组成的括号对，则r为（n-1-i）对括号组成的括号对
    //具体请参考：https://leetcode-cn.com/problems/generate-parentheses/solution/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/
    //讲解非常详细
    vector<string> generateParenthesis(int n)
    {
        if(!n)
            return {""};
        vector<string> res;
        for(int i = 0; i < n; i++)
        {
            for(string l : generateParenthesis(i))
            {
                for(string r : generateParenthesis(n - 1 - i))
                {
                    res.push_back('(' + l + ')' + r);
                }
            }
        }
        return res;
    }
};
// @lc code=end

