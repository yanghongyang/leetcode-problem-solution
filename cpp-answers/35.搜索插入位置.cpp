/*
 * @Author: your name
 * @Date: 2020-05-30 00:10:11
 * @LastEditTime: 2020-05-30 00:16:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\35.搜索插入位置.cpp
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
/*直接使用二分法
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};*/
/*手动实现一个二分法lower_bound*/
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto first = nums.begin(), last = nums.end();
        while (first < last)
        {
            auto mid = first + ((last - first) >> 1);
            if (*mid < target)
            {
                first = mid + 1;
            }
            else
            {
                last = mid;
            }
        }
        return first - nums.begin();
    }
};
// @lc code=end
