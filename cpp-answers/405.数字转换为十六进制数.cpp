/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 12:01:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 12:05:39
 */
/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        unsigned int ourNum = num;

        string str;
        char ourArray[17] = "0123456789abcdef";

        do
        {
            str += ourArray[ourNum % 16];
            ourNum /= 16;
        } while (ourNum);

        reverse(str.begin(), str.end());
        return str;
    }
};
// @lc code=end
