/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 17:09:30
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 17:24:36
 */
/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            //考虑每一个数字
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[j] >> i & 1) == 1)
                {
                    count++;
                }
            }
            if (count % 3 != 0)
            {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};
// @lc code=end
