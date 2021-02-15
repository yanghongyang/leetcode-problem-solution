/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int left = 0, right = 0;
        int cnt = 0;
        int n = nums.size();
        int mul = 1;
        for (right = 0; right < n; right++)
        {
            // 先乘以当前数字
            mul *= nums[right];
            // 然后滑左边
            while (mul >= k)
            {
                mul /= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};
// @lc code=end
