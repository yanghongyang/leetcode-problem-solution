/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-24 21:21:17
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-12-31 22:01:14
 */
/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        map<int, vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            ans[arr[i]].push_back(i);
        }
        vector<int> res(n, 0);
        int index = 1;
        for (auto x : ans)
        {
            for (auto y : x.second)
            {
                res[y] = index;
            }
            index++;
        }
        return res;
    }
};
// @lc code=end
