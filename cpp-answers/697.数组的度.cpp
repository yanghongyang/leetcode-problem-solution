/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-22 21:33:40
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 09:32:02
 */
/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        //双指针，首先扫描一遍求出数组的度，然后哈希表维护双指针指向的区间
        unordered_map<int, int> mp;
        int d = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            d = max(d, mp[nums[i]]);
        }
        unordered_map<int, int> mp2pointer;
        int l = 0, r = 0;
        int ans = 1e7;
        while (r < nums.size())
        {
            mp2pointer[nums[r]]++;
            if (mp2pointer[nums[r]] == d)
            {
                while (l <= r && mp2pointer[nums[r]] == d)
                {
                    mp2pointer[nums[l]]--;
                    l++;
                }
                ans = min(ans, r - l + 2);
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end
