/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-14 20:28:07
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-18 17:49:13
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto a : nums2)
        {
            if(m.count(a))
            {
                res.push_back(a);
                m.erase(a);
            }
        }
        return res;
    }
};
// @lc code=end
