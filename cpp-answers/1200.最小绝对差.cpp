/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-07-28 21:25:23
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-07-28 22:02:25
 */
/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> v;
        int n = arr.size();
        int mini = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int tmp = arr[i] - arr[i - 1];
            if (mini == tmp)
            {
                v.push_back({arr[i - 1], arr[i]});
            }
            else if (mini > tmp)
            {
                v.clear();
                mini = tmp;
                v.push_back({arr[i - 1], arr[i]});
            }
        }
        return v;
    }
};
// @lc code=end
