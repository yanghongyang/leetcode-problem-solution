/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-12 08:57:13
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-12 09:03:38
 */
/*
 * @lc app=leetcode.cn id=1482 lang=cpp
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
typedef long long ll;
class Solution
{
public:
    int check(int x, int n, vector<int> &bloomDay, int k)
    {
        vector<bool> flower(n);
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= x)
                flower[i] = true;
        }
        int bunch = 0;
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (flower[i])
                curr++;
            else
            {
                bunch += curr / k;
                curr = 0;
            }
        }
        bunch += curr / k;
        return bunch;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (n < k * m)
            return -1;
        int l = 1, r = 1e9;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, n, bloomDay, k) < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end
