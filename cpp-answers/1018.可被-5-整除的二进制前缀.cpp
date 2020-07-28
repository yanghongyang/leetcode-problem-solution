/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 19:34:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-24 19:41:53
 */
/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        vector<bool> res;
        int num = 0;
        for (int i = 0; i < A.size(); i++)
        {
            num = num * 2 + A[i];
            num = num % 5;
            res.push_back(num % 5 == 0);
        }
        return res;
    }
};
// @lc code=end
