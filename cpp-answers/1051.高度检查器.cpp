/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc cod  e=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        sort(heights.begin(), heights.end());
        int cnt = 0;
        for(int i = 0 ; i < tmp.size(); i++)
        {
            if(heights[i ] != tmp[i])
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

