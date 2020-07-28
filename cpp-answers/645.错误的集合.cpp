/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 22:05:14
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 22:07:46
 */
/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int dupl = -1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                dupl = nums[i];
                break;
            }
        }
        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
        }
        return {dupl, sum + dupl};
    }
};
// @lc code=end
