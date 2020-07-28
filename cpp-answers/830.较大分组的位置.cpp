/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-17 08:47:52
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 08:50:30
 */
/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> vRes;
        int start = 0, end = 0;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == S[i - 1])
                end++;
            if (S[i] != S[i - 1] || i == S.size() - 1)
            {
                if (end - start >= 2)
                {
                    vRes.push_back({start, end});
                }
                end = i;
                start = end;
            }
        }
        return vRes;
    }
};
// @lc code=end
