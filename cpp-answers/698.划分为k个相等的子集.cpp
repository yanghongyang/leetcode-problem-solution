/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-01 17:15:27
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-01 17:20:24
 */
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution
{
public:
    bitset<10001> visited;
    bool recur(vector<int> &nums, int sum, int k, int target, int lb)
    {
        if (k == 1)
            return true;
        if (sum == target)
            return recur(nums, 0, k - 1, target, 0);
        if (lb >= nums.size())
            return false;
        for (int i = lb; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                if (sum + nums[i] <= target)
                {
                    visited[i] = true;
                    if (recur(nums, sum + nums[i], k, target, i + 1))
                        return true;
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        if (!nums.size())
            return false;
        if (k == 1 && nums.size())
            return true;
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return recur(nums, 0, k, sum / k, 0);
    }
};
// @lc code=end
