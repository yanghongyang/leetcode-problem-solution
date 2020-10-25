/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-25 08:02:43
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-25 08:08:03
 */
/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int n = A.size();
        if (!n)
            return 0;
        vector<int> left(n);
        for (int i = 1; i < n; i++)
        {
            left[i] = (A[i - 1] < A[i]) ? left[i - 1] + 1 : 0;
        }
        vector<int> right(n);
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = (A[i + 1] < A[i]) ? right[i + 1] + 1 : 0;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (left[i] > 0 && right[i] > 0)
            {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
