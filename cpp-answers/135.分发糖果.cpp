/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int ans = 0;
        if (ratings.size() <= 0)
            return ans;
        int n = ratings.size();
        vector<int> cnt(n + 1, 1);
        for (int i = 1; i < n; i++) //从左到右
        {
            if (ratings[i] > ratings[i - 1])
            {
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) //从右到左
        {
            if (ratings[i] > ratings[i + 1])
            {
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            ans += cnt[i];
        }
        return ans;
    }
};
// @lc code=end