/*
 * @Author: your name
 * @Date: 2020-06-13 21:03:38
 * @LastEditTime: 2020-06-13 22:02:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \undefinede:\leetcode刷题\506.相对名次.cpp
 */
/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {"Gold Medal"};

        //将值和它的索引对应起来
        unordered_map<int, int> mp{};
        int i{};
        for (auto num : nums)
        {
            mp[num] = i;
            i++;
        }
        //排序，并且初始化答案
        sort(nums.begin(), nums.end());
        vector<string> ans(n, "");

        //将第4名到最后一名进行记录
        for (i = 0; n - i > 3; i++)
        {
            ans[mp[nums[i]]] = to_string(n - i);
        }

        //奖牌
        if (n > 2)
            ans[mp[nums[n - 3]]] = "Bronze Medal";
        ans[mp[nums[n - 2]]] = "Silver Medal";
        ans[mp[nums[n - 1]]] = "Gold Medal";

        return ans;
    }
};
// @lc code=end
