/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-01 18:50:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-01 19:47:38
 */
/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
class Solution
{
public:
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date)
    {
        int year = 0;
        int month = 0;
        int day = 0;
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            year *= 10;
            year += date[i] - '0';
        }
        for (int i = 5; i < 7; i++)
        {
            month *= 10;
            month += date[i] - '0';
        }
        for (int i = 8; i < 10; i++)
        {
            day *= 10;
            day += date[i] - '0';
        }
        int flag = 0; //flag代表是否是闰年
        if (year % 4 == 0 && year % 100 != 0)
            flag = 1;
        else if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
            flag = 1;
        for (int i = 1; i < month; i++)
        {
            ans += days[i];
        }
        if (month > 2)
        {
            if (flag == 1)
                ans += 1;
        }
        ans += day;
        return ans;
    }
};
// @lc code=end
