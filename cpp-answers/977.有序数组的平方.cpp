/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 21:07:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-22 21:15:31
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        //法一：忽略了“有序”这个条件
        /*
        vector<int> sol;
        for (int i = 0; i < A.size(); i++)
        {
            sol.push_back(A[i] * A[i]);
        }
        sort(sol.begin(), sol.end());
        return sol;
        */
        vector<int> sol;
        int l = 0, r = A.size() - 1; //左右指针
        while (l <= r)
        {
            int lv = A[l] * A[l];
            int rv = A[r] * A[r];

            if (lv <= rv)
            {
                sol.push_back(rv);
                r--;
            }
            else
            {
                sol.push_back(lv);
                l++;
            }
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
// @lc code=end
