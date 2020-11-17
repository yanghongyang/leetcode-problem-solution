/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-18 00:36:49
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-18 00:48:44
 */
/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> cnt(10002);

        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]] += nums[i];
        }

        vector<int> dp(10002);
        dp[1] = cnt[1];
        dp[2] = max(cnt[1], cnt[2]);
        for (int i = 3; i < dp.size(); i++)
        {
            dp[i] = max(dp[i - 2] + cnt[i], dp[i - 1]);
        }
        return max(dp[10000], dp[9999]);
    }
};
// @lc code=end
