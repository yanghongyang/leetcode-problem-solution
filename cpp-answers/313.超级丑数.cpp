/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-20 10:29:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-20 10:39:32
 */
/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        vector<int> ans(n);
        vector<int> kv(k, 0); //用来记录这k个数的指针位置，初始化为0
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                mini = min(mini, ans[kv[j]] * primes[j]);
            }
            for (int j = 0; j < k; j++)
            {
                if (mini == ans[kv[j]] * primes[j])
                {
                    kv[j]++;
                }
            }
            ans[i] = mini; //记录下最小值
        }
        return ans[n - 1];
    }
};
// @lc code=end
