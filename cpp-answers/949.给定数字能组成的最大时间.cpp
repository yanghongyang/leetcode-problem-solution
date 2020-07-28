/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 09:09:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 09:44:55
 */
/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 */

// @lc code=start
class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        string result = "";
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (i == j || j == k || k == i)
                        continue;
                    string hours = to_string(A[i]) + to_string(A[j]);
                    string minutes = to_string(A[k]) + to_string(A[6 - i - j - k]);
                    string time = hours + ":" + minutes;
                    if (hours < "24" && minutes < "60" && result < time)
                    {
                        result = time;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
