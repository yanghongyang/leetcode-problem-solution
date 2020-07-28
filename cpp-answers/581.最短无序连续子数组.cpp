/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 19:54:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 20:06:11
 */
/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution
{
public:
    /*     int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int start = nums.size();
        int end = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                {
                    start = min(start, i);
                    end = max(end, j);
                }
            }
        }
        return end - start >= 0 ? (end - start) + 1 : 0;
    } */
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int start = tmp.size();
        int end = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] != nums[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start >= 0) ? (end - start + 1) : 0;
    }
};
// @lc code=end
