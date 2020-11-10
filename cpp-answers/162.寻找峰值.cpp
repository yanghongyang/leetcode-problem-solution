/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-10 08:43:29
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-10 08:56:22
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution
{
public:
    /*     int findPeakElement(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high - 1)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return nums[low] > nums[high] ? low : high;
    } */
    int findPeakElement(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end
