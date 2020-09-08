/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-09-08 23:48:40
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-09-08 23:52:27
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (k == 0)
            return res;
        multiset<int> w;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i >= k)
                w.erase(w.find(nums[i - k]));
            w.insert(nums[i]);
            if (i >= k - 1)
                res.push_back(*w.rbegin());
        }
        return res;
    }
};
// @lc code=end
