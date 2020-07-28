/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 15:35:05
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 11:48:04
 */
/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

// @lc code=start
class Solution
{
public:
    int rotatedDigits(int N)
    {
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (check(i) == 0)
            {
                continue;
            }
            else
                cnt++;
        }
        return cnt;
    }

    int check(int num)
    {
        int count = 0;
        while (num > 0)
        {
            int a = num % 10;
            if (a == 3 || a == 7 || a == 4)
                return 0;
            if (a == 5 || a == 2 || a == 6 || a == 9)
                count++;
            num /= 10;
        }
        return count;
    }
};
// @lc code=end
