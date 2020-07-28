/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-12 21:02:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 11:53:59
 */
/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int maxi = *max_element(A.begin(), A.end());
        int mini = *min_element(A.begin(), A.end());
        if ((maxi - mini) <= 2 * K)
        {
            return 0;
        }
        return maxi - mini - 2 * K;
    }
};
// @lc code=end
