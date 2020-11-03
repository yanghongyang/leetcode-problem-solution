/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-03 16:34:41
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-03 16:38:17
 */
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] == nums[i - 2 - cnt])
                cnt++;
            else
                nums[i - cnt] = nums[i];
        }
        return n - cnt;
    }
};
// @lc code=end
