/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2021-01-04 22:44:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2021-01-04 23:02:22
 */
/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution
{
public:
    bool canReorderDoubled(vector<int> &A)
    {
        sort(A.begin(), A.end());
        unordered_map<double, int> m;
        for (int i = 0; i < A.size(); i++)
        {
            m[A[i]]++;
        }
        for (int i = 0; i < A.size(); i++)
        {
            if (!m[A[i]])
                continue;
            double tmp = A[i] > 0 ? A[i] * 2 : (double)A[i] / 2; //由于从小到大排序，因此负数时应为A[i]/2，正数时应为A[i]*2
            if (!m[tmp])
                return false;
            else
            {
                m[tmp]--;
                m[A[i]]--;
            }
        }
        return true;
    }
};
// @lc code=end
