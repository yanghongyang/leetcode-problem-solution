/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 19:58:53
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 20:00:16
 */
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int i = 0;
        int n = citations.size();
        while (i < n && citations[n - 1 - i] > i)
        {
            i++;
        }
        return i;
    }
};
// @lc code=end
