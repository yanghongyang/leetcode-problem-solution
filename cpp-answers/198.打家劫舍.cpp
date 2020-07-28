/*
 * @Author: your name
 * @Date: 2020-05-29 00:22:41
 * @LastEditTime: 2020-05-29 00:24:19
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\198.打家劫舍.cpp
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
// @lc code=end
