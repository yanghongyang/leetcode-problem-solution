/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 21:02:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 21:13:15
 */
/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
        {
            nums[i] = sorted[i & 1 ? k++ : j++];
        }
    }
};
// @lc code=end
