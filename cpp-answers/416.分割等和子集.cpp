/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-07 21:36:00
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-07 22:00:38
 */
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        //如果和为0，肯定可以划分成功
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - nums[i - 1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};
// @lc code=end
