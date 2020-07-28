/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 20:36:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 20:37:37
 */
/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution
{
public:
    string toLowerCase(string str)
    {
        //ASCII table upper case and lower case letters differ only by a single bit
        for (char &c : str)
        {
            if (c >= 'A' && c <= 'Z')
                c = c | 32;
        }
        return str;
    }
};
// @lc code=end
