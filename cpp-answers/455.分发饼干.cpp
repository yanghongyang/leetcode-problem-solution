/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-18 17:25:26
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:29:29
 */ 
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int assigned = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(assigned < g.size() && s[i] >= g[assigned])
                assigned++;
        }
        return assigned;
    }
};
// @lc code=end

