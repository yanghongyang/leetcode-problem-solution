/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 14:26:16
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 14:33:42
 */
/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
class Solution
{
public:
    /*     int cnt(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> count;
        int maxcnt = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            count[cnt(i)]++;
        }
        for (auto m : count)
        {
            if (maxcnt < m.second)
                maxcnt = m.second;
        }
        for (auto m : count)
        {
            if (maxcnt == m.second)
                ans++;
        }
        return ans;
    } */
    int cnt(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> count;
        int maxcnt = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int t = cnt(i);
            count[t]++;
            if (maxcnt < count[t])
                maxcnt = count[t];
        }
        for (auto m : count)
        {
            if (maxcnt == m.second)
                ans++;
        }
        return ans;
    }
};
// @lc code=end
