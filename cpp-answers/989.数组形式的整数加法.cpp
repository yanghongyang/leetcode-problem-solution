/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-28 11:38:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 11:46:50
 */
/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        vector<int> ans;
        int carry = 0; //用来计算每个数位及其进位
        int i = A.size() - 1;
        while (i >= 0 || carry > 0 || K != 0)
        {
            if (K != 0)
            {
                carry += K % 10; //加
                K /= 10;
            }
            if (i >= 0)
            {
                carry += A[i]; //加
                i--;
            }
            ans.push_back(carry % 10);
            carry /= 10; //更新进位
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
