/*
 * @Author: your name
 * @Date: 2020-05-28 22:02:49
 * @LastEditTime: 2020-05-28 22:09:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\14.最长公共前缀.cpp
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";
        string ans = "";
        sort(begin(strs), end(strs));
        string a = strs[0];
        string b = strs[n - 1];
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
                ans = ans + a[i];
            else
                break;
        }
        return ans;
    }
};
// @lc code=end
