/*
 * @Author: your name
 * @Date: 2020-05-30 01:04:34
 * @LastEditTime: 2020-05-30 01:07:59
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\67.二进制求和.cpp
 */
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ret = "";
        while (i >= 0 || j >= 0 || carry != 0)
        {
            if (i >= 0)
            {
                carry += a[i] == '0' ? 0 : 1;
                i--;
            }
            if (j >= 0)
            {
                carry += b[j] == '0' ? 0 : 1;
                j--;
            }
            ret = ((carry % 2) == 0 ? "0" : "1") + ret;
            carry /= 2;
        }
        return ret;
    }
};
// @lc code=end
