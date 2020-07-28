/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-20 11:52:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-05 17:47:57
 */
/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sumA = 0, sumB = 0;
        for (int a : A)
            sumA += a;
        for (int b : B)
            sumB += b;
        int delta = (sumB - sumA) >> 1;
        unordered_map<int, int> map;
        for (int a : A)
            map[a] = 1;
        for (int b : B)
        {
            if (map[b - delta]) //如果A中存在，那么就交换
            {
                return vector{b - delta, b};
            }
        }
        return {};
    }
};
// @lc code=end
