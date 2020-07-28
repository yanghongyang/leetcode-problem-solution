/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 22:48:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 22:50:45
 */
/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int cnt = 1;
        int maxi = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
            {
                cnt++;
            }
            else
            {
                if (cnt > maxi)
                    maxi = cnt;
                cnt = 1;
            }
        }
        if (cnt > maxi)
            maxi = cnt;
        return maxi;
    }
};
// @lc code=end
