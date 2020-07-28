/*
 * @Author: your name
 * @Date: 2020-06-05 20:56:39
 * @LastEditTime: 2020-06-05 21:00:17
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \-Insgram-e:\leetcode刷题\125.验证回文串.cpp
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string tmp = "";
        if (s == "")
            return true;
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
            {
                l++;
            }
            while (l < r && !isalnum(s[r]))
            {
                r--;
            }
            if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
};
// @lc code=end
