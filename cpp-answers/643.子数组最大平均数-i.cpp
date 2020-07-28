/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-12 10:07:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-12 10:11:08
 */
/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        int i = 0, j = 0;
        int maxi = 0;
        for (i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxi = sum;
        for (i = k; i < n; i++, j++)
        {
            sum -= nums[j];
            sum += nums[i];
            if (sum > maxi)
                maxi = sum;
        }
        return maxi / (double)k;
    }
};
// @lc code=end
