/*
 * @Author: your name
 * @Date: 2020-05-29 23:40:17
 * @LastEditTime: 2020-05-29 23:47:09
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\27.移除元素.cpp
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};
// @lc code=end
