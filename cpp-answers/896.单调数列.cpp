/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 22:59:39
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 23:03:15
 */
/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        bool increase = true;
        bool decrease = true;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] > A[i + 1])
                increase = false;
            if (A[i] < A[i + 1])
                decrease = false;
            if (increase == false && decrease == false)
                return false;
        }
        return true;
    }
};
// @lc code=end
