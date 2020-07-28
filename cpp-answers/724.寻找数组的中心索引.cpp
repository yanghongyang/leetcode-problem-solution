/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-16 08:16:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-16 08:38:25
 */
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int left = 0;
        int right = accumulate(begin(nums), end(nums), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (left == (right -= nums[i]))
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
// @lc code=end
