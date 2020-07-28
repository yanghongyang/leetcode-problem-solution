/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-08 05:01:33
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-08 05:29:29
 */
/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> v(A.size());
        int l = 0;
        int r = A.size() - 1;
        int i = 0;
        while (l <= r && i < A.size())
        {
            if (A[i] % 2 == 0)
                v[l++] = A[i++];
            else
                v[r--] = A[i++];
        }
        return v;
    }
};
// @lc code=end
