/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

// @lc code=start
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());

        if (nums[2] >= nums[0] + nums[1])
            return min(nums[2], nums[0] + nums[1]);
        return (a + b + c) / 2;
    }
};
// @lc code=end
