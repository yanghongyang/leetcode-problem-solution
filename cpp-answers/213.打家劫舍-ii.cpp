/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-10 08:38:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-10 08:40:51
 */
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
    int robber(vector<int> &nums, int start, int end)
    {
        int pre = 0, cur = 0;
        for (int i = start; i <= end; i++)
        {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
// @lc code=end
