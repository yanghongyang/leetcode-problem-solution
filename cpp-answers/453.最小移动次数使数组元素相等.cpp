/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-24 07:12:22
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-24 07:15:28
 */
/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        //给n-1个数+1，相当于给剩下的那个数-1，使所有数的差值不变，直到所有的数都变成最小值，也就是说所有的数与最小值的差就是题解。
        int minVal = *min_element(nums.begin(), nums.end());
        int ret = 0;
        for (const auto &n : nums)
            ret += n - minVal;
        return ret;
    }
};
// @lc code=end
