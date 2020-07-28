/*
 * @Author: your name
 * @Date: 2020-06-08 09:14:39
 * @LastEditTime: 2020-06-08 09:16:52
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\205.同构字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        char map_s[128] = {0};
        char map_t[128] = {0};
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (map_s[s[i]] != map_t[t[i]])
                return false;
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
