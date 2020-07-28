/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 21:33:40
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 21:37:59
 */
/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> times;
        int cnt = 0;
        int cnt_n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            times[nums[i]]++;
            if (times[nums[i]] >= cnt)
            {
                cnt = times[nums[i]];
                cnt_n = nums[i];
            }
        }
        int res = 0;
        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == cnt_n)
            {
                break;
            }
        }
        int j = 0;
        for (j = nums.size() - 1; j >= 0; j--)
        {
            if (nums[j] == cnt_n)
            {
                break;
            }
        }
        return j - i + 1;
    }
};
// @lc code=end
