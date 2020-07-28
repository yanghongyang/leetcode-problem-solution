/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-07 22:02:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-07 22:03:35
 */
/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int pos = distance(A.begin(), max_element(A.begin(), A.end()));
        return pos;
    }
};
// @lc code=end
