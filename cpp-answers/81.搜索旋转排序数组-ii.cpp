/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-05 08:53:37
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-05 09:01:21
 */
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            while (l < r && nums[l] == nums[l + 1])
            {
                l++;
            }
            while (l < r && nums[r] == nums[r - 1])
            {
                r--;
            }
            int m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                return true;
            }
            if (nums[m] > target)
            {
                if (nums[l] > nums[m] || nums[l] <= target)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if (nums[l] <= nums[m] || nums[l] > target)
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
