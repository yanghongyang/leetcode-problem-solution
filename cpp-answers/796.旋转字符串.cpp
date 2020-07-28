/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-05 17:54:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 17:57:56
 */
/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A == B)
            return true;
        int count = A.size();
        while (count--)
        {
            if (A == B)
                return true;
            const auto first = A[0];
            A.erase(A.begin());
            A.push_back(first);
        }
        return false;
    }
};
// @lc code=end
