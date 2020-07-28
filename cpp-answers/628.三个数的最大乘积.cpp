/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 21:26:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 21:31:16
 */
/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums.back(), nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};
// @lc code=end
