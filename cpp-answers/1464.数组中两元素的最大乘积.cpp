/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 17:48:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 17:50:15
 */
/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(int &a, int &b)
    {
        return a > b;
    }
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 2)
            return (nums[0] - 1) * (nums[1] - 1);
        sort(nums.begin(), nums.end(), cmp);
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
// @lc code=end
