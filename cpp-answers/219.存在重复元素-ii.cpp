/*
 * @Author: your name
 * @Date: 2020-06-08 22:59:07
 * @LastEditTime: 2020-06-09 08:25:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\219.存在重复元素-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;

        if (k <= 0)
            return false;
        if (k >= nums.size())
            k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) //如果i比k大，就删掉第i-k-1个旧元素
                s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }

        return false;
    }
};
// @lc code=end
