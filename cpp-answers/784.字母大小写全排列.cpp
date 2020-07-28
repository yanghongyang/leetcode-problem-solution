/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-19 09:11:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-19 09:16:55
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;

    vector<string> letterCasePermutation(string S)
    {
        dfs(S, 0);
        return ans;
    }

    void dfs(string &S, int index)
    {
        if (index == S.size())
        {
            ans.push_back(S);
            return;
        }
        //未修改当前字符（字母或数字）的一条分支
        dfs(S, index + 1);
        //修改当前字母的另一条分支
        if (isalpha(S[index]))
        {
            S[index] = S[index] ^ 32;
            dfs(S, index + 1);
        }
    }
};
// @lc code=end
