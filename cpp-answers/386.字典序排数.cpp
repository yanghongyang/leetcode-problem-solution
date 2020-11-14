/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 09:46:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 09:51:38
 */
/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution
{
public:
    void dfs(int num, int n, vector<int> &ans)
    {
        if (num > n)
            return;
        ans.push_back(num);
        for (int i = 0; i <= 9; i++)
        {
            dfs(num * 10 + i, n, ans);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= 9; i++)
        {
            dfs(i, n, ans);
        }
        return ans;
    }
};
// @lc code=end
