/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 09:22:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 09:25:02
 */
/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= nums[j])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
