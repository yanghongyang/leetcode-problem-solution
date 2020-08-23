/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-23 16:20:06
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-23 16:42:47
 */
/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution
{
public:
    //暴力模拟
    /*     vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
        }
        for (auto it : cnt)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    } */
    vector<int> singleNumber(vector<int> &nums)
    {
        int diff = 0;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            diff ^= nums[i];
        }
        diff = diff & (-diff);
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & diff)
            {
                x ^= nums[i];
            }
            else
            {
                y ^= nums[i];
            }
        }
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
// @lc code=end
