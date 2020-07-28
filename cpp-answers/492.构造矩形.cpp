/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 14:42:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 14:58:14
 */
/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        if (!area)
            return {};
        int p = sqrt(area), min = INT_MAX, l, r;
        while (p)
        {
            if (area % p == 0)
            {
                return {area / p, p};
            }
            else
                p--;
        }
        return {p, area / p};
    }
};
// @lc code=end
