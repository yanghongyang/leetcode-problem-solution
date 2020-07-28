/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:31:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:34:09
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
