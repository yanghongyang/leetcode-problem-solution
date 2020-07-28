/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 10:16:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 16:32:36
 */ 
/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, i = 0;
        while(i < nums.size())
        {
            while(i < nums.size() && nums[i] == 0)
                i++;
            int subMax = 0;
            while(i < nums.size() && nums[i] == 1)
            {
                subMax++;
                i++;
            }
            if(subMax > maxi)
                maxi = subMax;
        }
        return maxi;
    }
};
// @lc code=end

