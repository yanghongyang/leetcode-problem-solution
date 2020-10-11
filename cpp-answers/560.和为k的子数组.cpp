/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-10-11 08:00:10
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-10-11 08:07:19
 */
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution
{
public:
    //暴力法万岁！
    /*     int subarraySum(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j >= 0; j--)
            {
                sum += nums[j];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    } */
    //前缀和+哈希表
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int pre = 0;
        for (auto &x : nums)
        {
            pre += x;
            if (mp.find(pre - k) != mp.end())
                cnt += mp[pre - k];
            mp[pre]++;
        }
        return cnt;
    }
};
// @lc code=end
