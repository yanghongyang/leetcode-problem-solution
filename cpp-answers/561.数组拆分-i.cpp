/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 14:21:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 14:23:14
 */
/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            res += nums[i];
        }
        return res;
    }
};
// @lc code=end
