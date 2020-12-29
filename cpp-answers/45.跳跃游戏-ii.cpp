/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-12-29 23:00:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-29 23:45:41
 */
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int start = 0, end = 0;
        int maxLen = 0;
        while (end < nums.size() - 1)
        {
            for (int i = start; i <= end; i++)
            {
                maxLen = max(maxLen, i + nums[i]);
            }
            start = end + 1;
            end = maxLen;
            step++;
        }
        return step;
    }
};
// @lc code=end
