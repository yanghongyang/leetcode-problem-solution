/*
 * @Author: your name
 * @Date: 2020-06-06 22:50:20
 * @LastEditTime: 2020-06-06 22:55:52
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\202.快乐数.cpp
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int tran(int n)
    {
        int ans = 0;
        while (n)
        {
            ans += pow(n % 10, 2);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n)
    {
        bool rep[1000];
        memset(rep, 0, sizeof(rep));
        n = tran(n);
        while (!rep[n])
        {
            rep[n] = true;
            if (n == 1)
                return true;
            n = tran(n);
        }
        return false;
    }
};
// @lc code=end
