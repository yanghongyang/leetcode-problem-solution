/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:17:03
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-17 08:34:03
 */
/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

// @lc code=start
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int radius = 0;
        sort(heaters.begin(), heaters.end());
        for (auto house : houses)
        {
            if (house <= heaters.front())
            {
                radius = max(radius, heaters.front() - house);
                continue;
            }
            if (house >= heaters.back())
            {
                radius = max(radius, house - heaters.back());
                continue;
            }
            radius = max(radius, findAdjacentHeaters(house, heaters));
        }
        return radius;
    }
    int findAdjacentHeaters(int house, vector<int> &heaters)
    {
        int radius = 0;
        int l = 0;
        int r = heaters.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (heaters[mid] == house)
                return 0;
            if (heaters[mid] < house)
                l = mid + 1;
            if (heaters[mid] > house)
                r = mid - 1;
        }
        return min(heaters[l] - house, house - heaters[r]);
    }
};
// @lc code=end
