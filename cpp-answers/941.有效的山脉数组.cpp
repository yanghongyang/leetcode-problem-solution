/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-03 23:12:20
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 23:13:37
 */
/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int n = A.size();
        int i = 0;
        while (i < n - 1 && A[i] < A[i + 1])
            i++;
        if (i == n - 1 || i == 0)
            return false;
        while (i < n - 1 && A[i] > A[i + 1])
            i++;
        return (i == n - 1);
    }
};
// @lc code=end
