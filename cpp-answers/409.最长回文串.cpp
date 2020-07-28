/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 15:13:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 15:25:57
 */
/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> hash;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            hash[s[i]]++;
        }
        int flag = 0;
        int pal = 0;
        for (auto i = hash.begin(); i != hash.end(); i++)
        {
            if (i->second % 2 == 0)
            {
                pal += i->second;
            }
            else
            {
                flag = 1;
                pal += (i->second - 1);
            }
        }
        pal += flag;
        return pal;
    }
};
// @lc code=end
