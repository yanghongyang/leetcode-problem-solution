/*
 * @Author: your name
 * @Date: 2020-05-28 21:48:06
 * @LastEditTime: 2020-05-28 22:00:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\13.罗马数字转整数.cpp
 */
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        if (s.empty())
            return 0;
        unordered_map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; i--)
        {
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
    }
};
// @lc code=end
