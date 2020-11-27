/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-27 11:50:35
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-27 11:53:46
 */
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (auto a : A)
        {
            for (auto b : B)
            {
                mp[a + b]++;
            }
        }
        for (auto u : C)
        {
            for (auto v : D)
            {
                auto it = mp.find(-u - v);
                if (it != mp.end())
                {
                    cnt += it->second;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
