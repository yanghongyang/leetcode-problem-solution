/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-25 17:53:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-25 17:55:43
 */
/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target.size() != arr.size())
            return false;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
// @lc code=end
