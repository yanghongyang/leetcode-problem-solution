/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:04:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 08:08:05
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
// @lc code=end
