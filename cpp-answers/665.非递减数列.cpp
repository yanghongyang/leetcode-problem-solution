/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-18 16:25:47
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 16:37:54
 */
/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                if (i - 2 >= 0 && nums[i - 2] > nums[i])
                    nums[i] = nums[i - 1];
                else
                    nums[i - 1] = nums[i];
                cnt++;
            }
        }
        return cnt <= 1;
    }
};
// @lc code=end
