/*
 * @Author: your name
 * @Date: 2020-06-05 21:55:00
 * @LastEditTime: 2020-06-05 22:17:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\169.多数元素.cpp
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    /*哈希表解法
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (auto num : nums)
        {
            if (++counter[num] > nums.size() / 2)
            {
                return num;
            }
        }
        return 0;
    }*/
    /*nth_element方法
    int majorityElement(vector<int> &nums)
    {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }*/
    /*Moore投票法*/
    int majorityElement(vector<int> &nums)
    {
        int counter = 0, majority;
        for (int num : nums)
        {
            if (!counter)
            {
                majority = num;
            }
            counter += num == majority ? 1 : -1;
        }
        return majority;
    }
};
// @lc code=end
