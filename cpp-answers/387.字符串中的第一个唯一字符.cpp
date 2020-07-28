/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-13 22:29:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 12:13:14
 */
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> v(26, 0);
        for (char c : s)
            v[c - 'a']++;
        for (int i = 0; i < s.size(); i++)
        {
            if (v[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
