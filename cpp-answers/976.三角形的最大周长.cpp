/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 10:02:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 10:03:35
 */
/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0; i < A.size() - 2; i++)
        {
            if (A[i] < A[i + 1] + A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};
// @lc code=end
