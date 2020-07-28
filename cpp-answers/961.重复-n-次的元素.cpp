/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:29:08
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-20 11:30:12
 */
/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */

// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (A[i] == A[i + 1])
                return A[i];
        }
        return 0;
    }
};
// @lc code=end
