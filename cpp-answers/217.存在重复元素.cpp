/*
 * @Author: your name
 * @Date: 2020-06-08 22:52:33
 * @LastEditTime: 2020-06-08 22:58:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode刷题\217.存在重复元素.cpp
 */
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <set>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        /*
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
        */
        if (nums.size() <= 1)
            return false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                return true;
            }
            ++m[nums[i]];
        }
        return false;
    }
};
// @lc code=end
