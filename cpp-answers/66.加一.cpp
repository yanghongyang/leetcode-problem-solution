/*
 * @Author: your name
 * @Date: 2020-05-30 01:00:00
 * @LastEditTime: 2020-05-30 01:03:19
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\66.加一.cpp
 */
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0 && carry; i--)
        {
            carry = (++digits[i] %= 10) == 0;
        }

        if (carry)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
// @lc code=end
