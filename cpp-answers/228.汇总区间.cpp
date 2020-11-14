/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 19:29:48
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 19:32:43
 */
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int pre = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
                i++;
            if (pre == nums[i])
                res.push_back(to_string(pre));
            else
            {
                res.push_back(to_string(pre) + "->" + to_string(nums[i]));
            }
        }
        return res;
    }
};
// @lc code=end
