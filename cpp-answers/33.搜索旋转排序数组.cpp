/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-15 09:01:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-15 09:09:58
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (!n)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid]) //如果前半段有序
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else //如果前半段没有序，那就只能看后半段有没有顺序，也就是看nums[mid]到nums[n-1]这个范围内是否存在target
            {
                if (nums[mid] < target && nums[n - 1] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
