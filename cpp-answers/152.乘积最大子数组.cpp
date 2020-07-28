/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-06 17:58:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-06 18:03:06
 */
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int currentMax = nums[0];
        int currentMin = nums[0]; //要考虑正负号，所以保留当前乘积的最大值和最小值
        int maxProduct = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int p1 = currentMax * nums[i];
            int p2 = currentMin * nums[i];
            currentMax = max(nums[i], max(p1, p2));
            currentMin = min(nums[i], min(p1, p2));
            maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
        }
        return maxProduct;
    }
};
// @lc code=end
