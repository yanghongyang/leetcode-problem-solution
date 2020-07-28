/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 22:10:38
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 22:12:10
 */
/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int answer = 1, count = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                count++;
                answer = max(answer, count);
            }
            else
                count = 1;
        }
        return answer;
    }
};
// @lc code=end
