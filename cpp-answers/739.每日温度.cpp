/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> ans(n, 0);
        if (n <= 1)
            return ans;
        stack<int> warmer;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!warmer.empty() && T[i] >= T[warmer.top()])
            {
                /* code */
                warmer.pop();
            }
            if (!warmer.empty())
                ans[i] = warmer.top() - i;
            warmer.push(i);
        }
        return ans;
    }
};
// @lc code=end
