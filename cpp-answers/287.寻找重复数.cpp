/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-10 22:58:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-10 23:11:20
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        int left = 1, right = n - 1;
        int mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= mid)
                    cnt++;
            }
            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end
