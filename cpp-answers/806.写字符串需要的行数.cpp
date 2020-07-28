/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-18 07:11:11
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 10:54:19
 */
/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int strSize = S.size();
        int total = 0;
        int lines = 1;
        for (int i = 0; i < strSize; i++)
        {
            total += widths[S[i] - 'a'];
            if (total > 100)
            {
                lines++;
                total = 0;
                i--;
            }
        }
        return {lines, total};
    }
};
// @lc code=end
