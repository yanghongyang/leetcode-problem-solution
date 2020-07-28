/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 19:03:29
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 19:17:54
 */
/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int n = s.size();
        int counter = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                counter++;
            }
            else
                counter--;
            if (counter == 0)
                res++;
        }
        return res;
    }
};
// @lc code=end
