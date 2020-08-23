/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 15:56:54
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 16:04:20
 */
/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> v;
        vector<int> ans;
        for (auto a : arr)
        {
            int t = a;
            int cnt = 0;
            while (t)
            {
                t = t & (t - 1);
                cnt++;
            }
            v.push_back({cnt, a});
        }
        stable_sort(v.begin(), v.end());
        for (auto a : v)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};
// @lc code=end
