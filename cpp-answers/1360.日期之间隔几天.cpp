/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-22 15:40:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-22 15:50:48
 */
/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start
class Solution
{
public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(date_to_int(date2) - date_to_int(date1));
    }

    int date_to_int(string s_date)
    {
        int Y = stoi(s_date.substr(0, 4));
        int M = stoi(s_date.substr(5, 2));
        int D = stoi(s_date.substr(8, 2));

        int date = 0;
        for (int y = 1971; y < Y; y++)
        {
            date += is_leap_year(y) ? 366 : 365;
        }
        for (int m = 1; m < M; m++)
        {
            date += days_in_month(m, Y);
        }
        return date + D;
    }

    bool is_leap_year(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int days_in_month(int m, int year)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        if (m == 2)
            return is_leap_year(year) ? 29 : 28;
        return 30;
    }
};
// @lc code=end
