/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 11:20:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-08 11:21:49
 */
/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int i = 0, j = n;
        int k = 0;
        vector<int> res(nums.size());
        while (k < nums.size())
        {
            res[k] = k & 1 ? nums[j++] : nums[i++];
            k++;
        }
        return res;
    }
};
// @lc code=end
