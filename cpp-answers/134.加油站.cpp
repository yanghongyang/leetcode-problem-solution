/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if(curr < 0)    //如果到达不了当前车站
            {
                start = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
// @lc code=end

