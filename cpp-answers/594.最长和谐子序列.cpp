/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-27 23:43:25
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-03 23:33:16
 */
/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        map<int, int> dude;
        for (int i = 0; i < nums.size(); i++)
        {
            dude[nums[i]]++;
        }
        int result = 0;
        int lastnum, curnum, lastfr, curfr;
        auto it = dude.begin();
        lastfr = it->second;
        lastnum = it->first;
        it++;
        while (it != dude.end())
        {
            curnum = it->first;
            curfr = it->second;
            if (curnum - 1 == lastnum)
            {
                result = max(result, (curfr + lastfr));
            }
            lastnum = curnum;
            lastfr = curfr;
            it++;
        }
        return result;
    }
};
// @lc code=end
