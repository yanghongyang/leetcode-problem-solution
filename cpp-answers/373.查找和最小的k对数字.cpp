/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-11-14 09:08:34
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-11-14 09:13:13
 */
/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums2.empty() || nums1.empty())
            return {};
        priority_queue<pair<int, vector<int>>> maxheap;
        vector<vector<int>> res;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (maxheap.size() < k)
                {
                    maxheap.push({nums1[i] + nums2[j], vector<int>({nums1[i], nums2[j]})});
                }
                else if (maxheap.size() == k && (nums1[i] + nums2[j] < maxheap.top().first))
                {
                    maxheap.pop();
                    maxheap.push({nums1[i] + nums2[j], vector<int>({nums1[i], nums2[j]})});
                }
            }
        }

        while (!maxheap.empty())
        {
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return res;
    }
};
// @lc code=end
