/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:09:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 08:15:16
 */
/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j)
            {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
// @lc code=end
