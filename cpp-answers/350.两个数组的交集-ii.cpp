/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 08:21:32
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 08:26:19
 */
/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ctr;
        for (int i : nums1)
        {
            ctr[i]++;
        }
        vector<int> out;
        for (int i : nums2)
        {
            if (ctr[i]-- > 0)
            {
                out.push_back(i);
            }
        }
        return out;
    }
};
// @lc code=end
