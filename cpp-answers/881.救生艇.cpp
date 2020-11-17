/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-18 01:07:42
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-18 01:15:04
 */
/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        //用一下贪心？
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int l = 0, r = n - 1, btcnt = 0;
        //贪心一下，每一次选择最大的和最小的组成一组，如果能组成，那就l++
        while (l <= r)
        {
            if ((limit - people[r]) >= people[l]) //嘛，因为最多承载两个人嘛，所以直接l++就行了，说明能带走瘦子！
                l++;
            btcnt++;
            r--;
        }
        return btcnt;
    }
};
// @lc code=end
