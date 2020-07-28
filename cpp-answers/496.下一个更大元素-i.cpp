/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-06-23 12:26:19
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-06-23 12:34:53
 */
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        //维护单调栈
        unordered_map<int, int> m;
        stack<int> s;
        for (auto x : nums2)
        {
            while (!s.empty() && s.top() < x)
            {
                m[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for (auto &x : nums1)
            x = m.count(x) ? m[x] : -1;
        return nums1;
    }
};
// @lc code=end
