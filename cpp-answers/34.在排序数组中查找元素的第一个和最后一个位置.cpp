/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-28 18:16:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-28 18:27:42
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target + 1) - 1;
        if (idx1 < nums.size() && nums[idx1] == target)
        {
            return {idx1, idx2};
        }
        else
        {
            return {-1, -1};
        }
    }
};
// @lc code=end
