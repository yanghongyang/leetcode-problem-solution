/*
 * @Author: your name
 * @Date: 2020-06-13 19:06:02
 * @LastEditTime: 2020-06-13 19:11:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\242.有效的字母异位词.cpp
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        /*
        if (s.length() != t.length())
            return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++)
        {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
        {
            if (count.second)
                return false;
        }
        return true;
        */
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
