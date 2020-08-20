/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 09:42:05
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 10:12:05
 */
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution
{
public:
    /* int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; i++)
        {
            k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
            if (k[i] == k[t2] * 2)
                t2++;
            if (k[i] == k[t3] * 3)
                t3++;
            if (k[i] == k[t5] * 5)
                t5++;
        }
        return k[n - 1];
    } */
    int nthUglyNumber(int n)
    {
        priority_queue<double, vector<double>, greater<double>> q;
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        double ans = 1;
        for (int i = 1; i < n; i++)
        {
            q.push(ans * 2);
            q.push(ans * 3);
            q.push(ans * 5);
            ans = q.top();
            q.pop();
            //去掉重复元素
            while (!q.empty() && ans == q.top())
                q.pop();
        }
        return ans;
    }
};
// @lc code=end
