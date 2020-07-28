/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 21:41:01
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-27 21:49:42
 */
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    //贪心
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int n = nums.size();
        int max_index_can_jump = 0; //当前可以到达的最远位置
        for (int i = 0; i <= max_index_can_jump; i++)
        {
            if ((nums[i] + i) > max_index_can_jump)
            {
                if ((nums[i] + i) >= (n - 1))
                    return true;
                else
                {
                    max_index_can_jump = nums[i] + i;
                }
            }
        }

        return max_index_can_jump == (n - 1);
    }
};
// @lc code=end
