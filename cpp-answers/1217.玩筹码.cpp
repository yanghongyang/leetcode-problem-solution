/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-28 21:14:55
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 21:22:21
 */
/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        int n = chips.size();
        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            if (chips[i] % 2 == 0)
                m["even"]++;
            else
                m["odd"]++;
        }
        return min(m["odd"], m["even"]);
    }
};
// @lc code=end
