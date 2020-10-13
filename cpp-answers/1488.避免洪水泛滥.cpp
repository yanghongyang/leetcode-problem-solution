/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-13 08:15:04
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-13 08:21:30
 */
/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        vector<int> ans(rains.size(), -1);
        unordered_map<int, int> water;
        set<int> zero;

        for (int i = 0; i < rains.size(); i++)
        {
            int r = rains[i];

            if (r == 0)
            {
                //如果可以抽水的话，把该日记录到zero中
                zero.insert(i);
                continue;
            }
            if (water.count(r) != 0)
            {
                //如果该日已经满了，那就找到zero中最开始的那一天
                auto it = zero.lower_bound(water[r]);
                if (it == zero.end())
                    return {}; //没有符合的zero的一天
                ans[*it] = r;  //找到了，把*it对应的ans值换成r
                zero.erase(it);
            }
            //每次更新当前的water[r]对应的天数
            water[r] = i;
            ans[i] = -1;
        }
        return ans;
    }
};
// @lc code=end
